#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

static const char proj[] = "PROJECT NF CCs";

const char name[] = "Diego A.";
const char noise[] = "MISAKA NETWORK";
const char atk[] = "CHAOS CONTROL";
const char def[] = "IMAGINE BREAKER";
const char quote2[] = "The time-space rift is expanding... There's no more time, I need to hurry.";
const char quote3[] = "Sounds good but you should know only the Power Rangers can control the Mega Voyger.";
const char quote4[] = "Step aside Mercury, it's not you I'm after!";

const char spell4[] = "Bao Zakeruga";

const char rando0[] = "Sparkling Wide Pressure";
const char rando1[] = "Exodia the Forbidden One";
const char rando2[] = "VOLCAN 300";

const char end1[] = "You foolish man, I am a Jito-Ryo master. Allow me to reunite you with your ancestors.";
const char end2[] = "Jump on panel number one, it will take you to panels two and three.";

typedef struct _SUBData
{
	float hours; //unused, CC I'm wanting are from 20m episodes
	float mins;
	float secs;
	float x_pos;
	float y_pos;
	int startline;
} SUBData;

//SUBData * sub_main_data = NULL;

int CountAllLines(int8_t* datBuf, int fileSz)
{
	int lines = 0;
	int j = 0;
	for(j = 0; j<fileSz; ++j) {
		if(datBuf[j] == 0x44 && datBuf[j+1] == 0x69 && datBuf[j+46] == 0x30) { //assume line
			++lines;
		}
	}
	
	return lines;
}

void TweakData(int8_t* datBuf, int initial, int fileSz, int allLines)
{
	SUBData * subLines = (SUBData *) malloc(allLines*sizeof(SUBData));
	
	int lineCNT = 0;
	uint8_t line123 = 1;
	int inbetweenLINE = 0;
	
	int topLINE = 0; // record top line byte start of Dialogue:
	
	char tmpStr[8] = {0};
	char tmpStrX[8] = {0};
	char tmpStrY[8] = {0};
	int j = 0;
	//printf("Reportin': 0x%X, 0x%X, 0x%X\n", datBuf[0x2F6], datBuf[0x2F6+1], datBuf[0x2F6+46]);
	for(j = initial; j<fileSz; ++j) {
		if(datBuf[j] == 0x44 && datBuf[j+1] == 0x69 && datBuf[j+46] == 0x30) { //assume line
			++lineCNT;
			//printf("Found line #%d.\n", lineCNT);
	
			// Record byte pos of file
			//subLines[lineCNT-1].startline = j;

			if(datBuf[j+16] == 0x3A) { //semicolon
				snprintf(tmpStr, 0x2, &datBuf[j+14]);
				subLines[lineCNT-1].mins = atoi(tmpStr);
				//	printf("Show mins: %d\n", atoi(tmpStr));
			}
			
			if(datBuf[j+22] == 0x2C) { //comma
				snprintf(tmpStr, 0x5, &datBuf[j+17]);
				subLines[lineCNT-1].secs = atof(tmpStr);
				//	printf("Show secs: %g\n", atof(tmpStr));
			}
			
			//if(subYpos) {
		//	{
				int b = 0;
				for(b = 0; b<15; b++) { //find comma
					if(datBuf[j+59+b] == 0x2C) {
						//printf("Found comma!\n");
						break;
					}
				}
				if((datBuf[j+59+b+1] & 0xF0) == 0x30) { //is a number
					//printf("Found y pos of line %d.\n", lineCNT);
					// Record Y pos
					snprintf(tmpStrY, 0x7, &datBuf[j+59+b+1]);
					subLines[lineCNT-1].y_pos = atof(tmpStrY);
					
					// Record file pos of y
					subLines[lineCNT-1].startline = j+59+b+1;
					//	printf("Show: %s\n", tmpStr);
					//	printf("Show: %g\n", atof(tmpStr));
				}
		//	}
		}
	}
	//	printf("Show: %g:%g, y pos: %g\n", subLines[1-1].mins, subLines[1-1].secs, subLines[1-1].y_pos);
	//bool is3 = false;
	int count3 = 0;
	int n = 0;
	for(n = 1; n<lineCNT; ++n) {
		if(subLines[n-1].mins == subLines[n].mins && subLines[n].mins == subLines[n+1].mins) {
			if(subLines[n-1].secs == subLines[n].secs && subLines[n].secs == subLines[n+1].secs) {
				++count3;
				//is3 = true;
				
				printf("Found Triple Liner #%d\n", count3);
				
				float newLineTop = 0;
				newLineTop = subLines[n-1+2].y_pos - subLines[n].y_pos;
				newLineTop = subLines[n].y_pos - newLineTop;
				
				printf("Line %d, new pos: %g, old pos: %g\n\n", n, newLineTop, subLines[n-1].y_pos);
				// Write new Y pos
				char resVal[8] = {0};
				sprintf(resVal, "%g", newLineTop);
				uint8_t x = 0;
				for(x = 0; x<9; ++x) {
					if(datBuf[subLines[n-1].startline+x] == 0x29)
						break;
					datBuf[subLines[n-1].startline+x] = resVal[x];
				}
			}
		}
	}
	//	printf("There are three lines: %d\n", count3);
	free(subLines);
}

int main (int argc, char *argv[])
{
  int i = 0;
  int x = 0;
  int fullLimit = 0;
  int halfLimit = 0;
  int halfLimit1 = 0; //for recording game string len
  int fullLimit1 = 0;
  bool lineBroke = false;
  int checksum = 0;

  printf("\n\n");
  printf("~ Netflix CC 3-Line Tweaker ~  by %s\n\n\n", name);
  
  int d = 0;
  int fileSz = 0;

  int workType = 1;
  FILE *fd = NULL;

  if(argc > 1) {
    for(i = 1; i < (argc-1); i++) {
            //need to handle special characters or commands
			
			if(strcmp(argv[i], "-i") == 0) {
				fd = fopen(argv[i+1], "rb");
				if(fd == NULL) {
					printf("Failed to open file!\nAre you reading the right spell book?\n\n");
					break;
				} else
					printf("Opened file for reading: %s\n\n", argv[i+1]);
			}
			
		/*	if(strcmp(argv[i], "-d") == 0) {
				workType = 1;
				printf("Input will be decoded...\n");
            } */
			
            if(strcmp(argv[i], "/help") == 0) //print all commands and instructions
            {
                ++i;   //skip arg
                x = 0; //reset parse
                //printf("\n");
                printf("USAGE INSTRUCTIONS:\n");
                printf("nf2ass.exe -i nf2ass.ass\n\n");
                printf("This tool modifies YTSubConverter ASS files\n");
                printf("converted from Netflix EIA-608 TTML files.\n");
                printf("This is because when 3 lines are used,\n");
                printf("the top line is positioned slightly wrong.\n\n");
                printf("NOTE: 608 captions can use up to 4 lines. Need to handle that, too.\n\n");
                //printf("\n");
            }
			
			//work
			if(workType == 1) { //decode
				// get file size
				fseek(fd, 0, SEEK_END);
				fileSz = ftell(fd);
				
				// read the file into mem
				fseek(fd, 0, SEEK_SET);
				uint8_t* datBuf = malloc(fileSz);
				fread(datBuf, 1, fileSz, fd);
				
				int allLines = CountAllLines(datBuf, fileSz);
				TweakData(datBuf, 572, fileSz, allLines);
				
				// write file
				FILE* fout = fopen("tweaked.ass", "wb");
				fwrite(datBuf, 1, fileSz, fout);
				fclose(fout);
				
				free(datBuf);
				
				printf("\n");
				printf("Done!\n");
			} //else {
				//printf("No command selected...\n");
			//}
		}
  }
  else
  {
     printf("No arguments.\n");
     printf("Use /help to list usage instructions.\n");
  }
  
  fclose(fd);

  printf("\n");

  return 0;
}
