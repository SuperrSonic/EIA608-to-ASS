#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * COMPILE GUIDE
 *
 * APP BUILD
 * C:\MinGW\bin\gcc "C:\path\cc2ass.c" -o "C:\cc2ass.exe" icon.res
 *
 * ICON BUILD
 * C:\MinGW\bin\windres "C:\my.rc" -O coff -o "C:\my.res"
*/

static const char proj[] = "PROJECT CC TWEAKER";

// NOTE: I like to sugarcoat my tools, originally for checksum reasons
// now mostly to amuse myself.

const char name[] = "Diego A.";
const char noise[] = "MISAKA NETWORK";
const char atk[] = "CHAOS CONTROL";
const char def[] = "IMAGINE BREAKER";
const char quote2[] = "The time-space rift is expanding... There's no more time, I need to hurry.";
const char quote3[] = "Sounds good but you should know only the Power Rangers can control the Mega Voyger.";

const char spell4[] = "Bao Zakeruga";

const char rando0[] = "Sparkling Wide Pressure";
const char rando1[] = "Exodia the Forbidden One";
const char rando2[] = "VOLCAN 300";

const char end1[] = "You foolish man, I am a Jito-Ryo master. Allow me to reunite you with your ancestors.";
const char end2[] = "Jump on panel number one, it will take you to panels two and three.";

const unsigned char assHeader[] = {
	0x5b, 0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x20, 0x49, 0x6e, 0x66, 0x6f, 0x5d, 0x0d, 0x0a, 0x3b, 
	0x20, 0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x20, 0x67, 0x65, 0x6e, 0x65, 0x72, 0x61, 0x74, 0x65, 
	0x64, 0x20, 0x62, 0x79, 0x20, 0x46, 0x46, 0x6d, 0x70, 0x65, 0x67, 0x2f, 0x4c, 0x61, 0x76, 0x63, 
	0x0d, 0x0a, 0x53, 0x63, 0x72, 0x69, 0x70, 0x74, 0x54, 0x79, 0x70, 0x65, 0x3a, 0x20, 0x76, 0x34, 
	0x2e, 0x30, 0x30, 0x2b, 0x0d, 0x0a, 0x50, 0x6c, 0x61, 0x79, 0x52, 0x65, 0x73, 0x58, 0x3a, 0x20, 
	0x33, 0x38, 0x34, 0x0d, 0x0a, 0x50, 0x6c, 0x61, 0x79, 0x52, 0x65, 0x73, 0x59, 0x3a, 0x20, 0x32, 
	0x38, 0x38, 0x0d, 0x0a, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x64, 0x42, 0x6f, 0x72, 0x64, 0x65, 0x72, 
	0x41, 0x6e, 0x64, 0x53, 0x68, 0x61, 0x64, 0x6f, 0x77, 0x3a, 0x20, 0x79, 0x65, 0x73, 0x0d, 0x0a, 
	0x0d, 0x0a, 0x5b, 0x56, 0x34, 0x2b, 0x20, 0x53, 0x74, 0x79, 0x6c, 0x65, 0x73, 0x5d, 0x0d, 0x0a, 
	0x46, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x3a, 0x20, 0x4e, 0x61, 0x6d, 0x65, 0x2c, 0x20, 0x46, 0x6f, 
	0x6e, 0x74, 0x6e, 0x61, 0x6d, 0x65, 0x2c, 0x20, 0x46, 0x6f, 0x6e, 0x74, 0x73, 0x69, 0x7a, 0x65, 
	0x2c, 0x20, 0x50, 0x72, 0x69, 0x6d, 0x61, 0x72, 0x79, 0x43, 0x6f, 0x6c, 0x6f, 0x75, 0x72, 0x2c, 
	0x20, 0x53, 0x65, 0x63, 0x6f, 0x6e, 0x64, 0x61, 0x72, 0x79, 0x43, 0x6f, 0x6c, 0x6f, 0x75, 0x72, 
	0x2c, 0x20, 0x4f, 0x75, 0x74, 0x6c, 0x69, 0x6e, 0x65, 0x43, 0x6f, 0x6c, 0x6f, 0x75, 0x72, 0x2c, 
	0x20, 0x42, 0x61, 0x63, 0x6b, 0x43, 0x6f, 0x6c, 0x6f, 0x75, 0x72, 0x2c, 0x20, 0x42, 0x6f, 0x6c, 
	0x64, 0x2c, 0x20, 0x49, 0x74, 0x61, 0x6c, 0x69, 0x63, 0x2c, 0x20, 0x55, 0x6e, 0x64, 0x65, 0x72, 
	0x6c, 0x69, 0x6e, 0x65, 0x2c, 0x20, 0x53, 0x74, 0x72, 0x69, 0x6b, 0x65, 0x4f, 0x75, 0x74, 0x2c, 
	0x20, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x58, 0x2c, 0x20, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x59, 0x2c, 
	0x20, 0x53, 0x70, 0x61, 0x63, 0x69, 0x6e, 0x67, 0x2c, 0x20, 0x41, 0x6e, 0x67, 0x6c, 0x65, 0x2c, 
	0x20, 0x42, 0x6f, 0x72, 0x64, 0x65, 0x72, 0x53, 0x74, 0x79, 0x6c, 0x65, 0x2c, 0x20, 0x4f, 0x75, 
	0x74, 0x6c, 0x69, 0x6e, 0x65, 0x2c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x6f, 0x77, 0x2c, 0x20, 0x41, 
	0x6c, 0x69, 0x67, 0x6e, 0x6d, 0x65, 0x6e, 0x74, 0x2c, 0x20, 0x4d, 0x61, 0x72, 0x67, 0x69, 0x6e, 
	0x4c, 0x2c, 0x20, 0x4d, 0x61, 0x72, 0x67, 0x69, 0x6e, 0x52, 0x2c, 0x20, 0x4d, 0x61, 0x72, 0x67, 
	0x69, 0x6e, 0x56, 0x2c, 0x20, 0x45, 0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0x0d, 0x0a, 0x53, 
	0x74, 0x79, 0x6c, 0x65, 0x3a, 0x20, 0x44, 0x65, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x2c, 0x56, 0x43, 
	0x52, 0x20, 0x4f, 0x53, 0x44, 0x20, 0x4d, 0x6f, 0x6e, 0x6f, 0x2c, 0x31, 0x36, 0x2c, 0x26, 0x48, 
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2c, 0x26, 0x48, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2c, 
	0x26, 0x48, 0x30, 0x2c, 0x26, 0x48, 0x30, 0x2c, 0x30, 0x2c, 0x30, 0x2c, 0x30, 0x2c, 0x30, 0x2c, 
	0x31, 0x30, 0x30, 0x2c, 0x31, 0x30, 0x30, 0x2c, 0x30, 0x2c, 0x30, 0x2c, 0x33, 0x2c, 0x31, 0x2c, 
	0x30, 0x2c, 0x37, 0x2c, 0x31, 0x30, 0x2c, 0x31, 0x30, 0x2c, 0x31, 0x30, 0x2c, 0x30, 0x0d, 0x0a, 
	0x0d, 0x0a, 0x5b, 0x45, 0x76, 0x65, 0x6e, 0x74, 0x73, 0x5d, 0x0d, 0x0a, 0x46, 0x6f, 0x72, 0x6d, 
	0x61, 0x74, 0x3a, 0x20, 0x4c, 0x61, 0x79, 0x65, 0x72, 0x2c, 0x20, 0x53, 0x74, 0x61, 0x72, 0x74, 
	0x2c, 0x20, 0x45, 0x6e, 0x64, 0x2c, 0x20, 0x53, 0x74, 0x79, 0x6c, 0x65, 0x2c, 0x20, 0x4e, 0x61, 
	0x6d, 0x65, 0x2c, 0x20, 0x4d, 0x61, 0x72, 0x67, 0x69, 0x6e, 0x4c, 0x2c, 0x20, 0x4d, 0x61, 0x72, 
	0x67, 0x69, 0x6e, 0x52, 0x2c, 0x20, 0x4d, 0x61, 0x72, 0x67, 0x69, 0x6e, 0x56, 0x2c, 0x20, 0x45, 
	0x66, 0x66, 0x65, 0x63, 0x74, 0x2c, 0x20, 0x54, 0x65, 0x78, 0x74, 0x0d, 0x0a
};
const int assHeader_size = sizeof(assHeader);

typedef struct _SUBData
{
	float hours; //unused, CC I'm wanting are from 20m episodes
	float mins;
	float secs;
	float x_pos;
	float y_pos;
	int startline;
} SUBData;

typedef struct _EventData
{
	char lines[512];
} EventData;

int CountAllLines(int8_t* datBuf, int fileSz)
{
	int lines = 0;
	int j = 0;
	for(j = 0; j<fileSz; ++j) {
		if(datBuf[j] == 0x44 && datBuf[j+1] == 0x69 && datBuf[j+10] == 0x30) { //assume line
			++lines;
		}
	}
	
	return lines;
}

uint8_t arr_italic[6] = {0x5C, 0x69, 0x31, 0x7D, 0x7B, 0x00};
uint8_t arr_italicON[6] = {0x7B, 0x5C, 0x69, 0x31, 0x7D, 0x00};
uint8_t arr_italicOFF[6] = {0x7B, 0x5C, 0x69, 0x30, 0x7D, 0x00};

int TweakData(uint8_t* datBuf, int initial, int fileSz, int allLines, uint8_t* outBuf)
{
	SUBData * subLines = (SUBData *) malloc(allLines*sizeof(SUBData));
	EventData * evDialogue = (EventData *) malloc(allLines*sizeof(EventData));
	
	char finalAss[512*1024] = {0};
	
	int lineCNT = 0;
	uint8_t line123 = 1;
	int inbetweenLINE = 0;
	
	int topLINE = 0; // record top line byte start of Dialogue:
	
	bool hasItalic = false;
	bool hasItalicOFF = false;
	
	char tmpStr[8] = {0};
	char tmpStrX[8] = {0};
	char tmpStrY[8] = {0};
	int j = 0;
	//printf("Reportin': 0x%X, 0x%X, 0x%X\n", datBuf[0x2F6], datBuf[0x2F6+1], datBuf[0x2F6+46]);
	for(j = initial; j<fileSz; ++j) {
		if(datBuf[j] == 0x44 && datBuf[j+1] == 0x69 && datBuf[j+10] == 0x30) { //assume line
			++lineCNT;
			//printf("Found line #%d.\n", lineCNT);
	
			// Record byte pos of file
			//subLines[lineCNT-1].startline = j;
			
			// Record each event into the buffer
			int y = 0;
			for(y=0; y<512; ++y) {
				if(datBuf[j+y] == 0x0D)// newline found
					break;
			}
			snprintf(evDialogue[lineCNT-1].lines, y, "%s", &datBuf[j]);
			
			int it = 0;
			for(it = 0; it<y; ++it) {
				if((evDialogue[lineCNT-1].lines[it] == arr_italicON[0]) && (evDialogue[lineCNT-1].lines[it+1] == arr_italicON[1])
				&& (evDialogue[lineCNT-1].lines[it+3] == arr_italicON[3])) {
					hasItalic = true;
					break;
				}
			}
			
			for(it = 0; it<y; ++it) {
				if((evDialogue[lineCNT-1].lines[it] == arr_italicON[0]) && (evDialogue[lineCNT-1].lines[it+1] == arr_italicON[1])
				&& (evDialogue[lineCNT-1].lines[it+3] == arr_italicOFF[3])) {
					hasItalicOFF = true;
					break;
				}
			}
			
			if(hasItalic && !hasItalicOFF)
				printf("Found italic tag, but not end tag. Line: %d\n", lineCNT);
			hasItalic = false;
			hasItalicOFF = false;

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
#if 0
	// This code is for a previous tool that fixes the y pos of ytsubconverter reversed files.
	int count3 = 0;
	int n = 0;
	for(n = 1; n<lineCNT; ++n) {
		if(subLines[n-1].mins == subLines[n].mins && subLines[n].mins == subLines[n+1].mins) {
			if(subLines[n-1].secs == subLines[n].secs && subLines[n].secs == subLines[n+1].secs) {
				++count3;
				
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
#endif
	if(lineCNT != 0) {
		int cntBreaks = 0;
		int b = 0;
		
		for(b = 0; b<lineCNT; ++b) {
			int c = 0;
			bool firstPos = false;
			int x = 0;
			int y = 0;
			int x_tmp = 0;
			int y_tmp = 0;
			int lineStart = 0;
			int brk1 = 0;
			int brk2 = 0;
			int brk3 = 0;
			bool keepLine1 = false;
			char tmpSTR[512] = {0};
		//	const char nBreak[4] = "\\N";
		//	char *token;
			cntBreaks = 0;
			for(c = 34; c<512; ++c) {
				// First \pos
				if(evDialogue[b].lines[c] == 0x5C && evDialogue[b].lines[c+1] == 0x70 && !firstPos) {
					// record x
					x = atoi(&evDialogue[b].lines[c+5]);
					if(evDialogue[b].lines[c+6] == 0x2C) {
						// record y
						y = atoi(&evDialogue[b].lines[c+7]);
					}
					else if(evDialogue[b].lines[c+7] == 0x2C) {
						// record y
						y = atoi(&evDialogue[b].lines[c+8]);
					}
					else if(evDialogue[b].lines[c+8] == 0x2C) {
						// record y
						y = atoi(&evDialogue[b].lines[c+9]);
					}
					firstPos = true;
					lineStart = c;
					//printf("X: %d, Y: %d\n", x, y);
				}
				
				// Scan for italic tags and adjust them for splitting
				hasItalic = false;
				hasItalicOFF = false;
				int it = 0;
				for(it = 0; it<512; ++it) {
					if((evDialogue[b].lines[it] == arr_italicON[0]) && (evDialogue[b].lines[it+1] == arr_italicON[1])
					&& (evDialogue[b].lines[it+3] == arr_italicON[3])) {
						hasItalic = true;
						break;
					}
				}
				
				for(it = 0; it<512; ++it) {
					if((evDialogue[b].lines[it] == arr_italicON[0]) && (evDialogue[b].lines[it+1] == arr_italicON[1])
					&& (evDialogue[b].lines[it+3] == arr_italicOFF[3])) {
						hasItalicOFF = true;
						break;
					}
				}
				
				
				if(evDialogue[b].lines[c] == 0x5C && evDialogue[b].lines[c+1] == 0x4E)
					++cntBreaks;
				
				if(cntBreaks == 1 && brk1 == 0) {
					brk1 = c;
					
				}
				else if(cntBreaks == 2 && brk2 == 0) {
					brk2 = c;
					
				}
				else if(cntBreaks == 3 && brk3 == 0) {
					brk3 = c;
				}
				
				if(c == 511) { //finished searching line
					// We now know how many linebreaks there are
					
					// Just do it the simple way and split every \N into its own event
					sprintf(tmpSTR, "%s", evDialogue[b].lines);
					if(brk1 != 0)
						tmpSTR[brk1] = 0;
					if(tmpSTR[strlen(tmpSTR)-1] == 0x0D)
						tmpSTR[strlen(tmpSTR-1)] = 0;
					sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
					
					if(brk1 != 0) {
						sprintf(tmpSTR, "%s", evDialogue[b].lines);
						tmpSTR[lineStart] = 0;
						sprintf(finalAss + strlen(finalAss), "%s", tmpSTR);
						
						// Append italic tag if start tag exists
						if(hasItalic && !hasItalicOFF) {
							printf("Added italic tag. Line: %d\n", b);
							sprintf(finalAss + strlen(finalAss), "%s", (char*)arr_italic);
						}
						
						sprintf(tmpSTR, "%s", &evDialogue[b].lines[brk1+3]);
						int g = 0;
						for(g=0; g<500;++g) {
							if(tmpSTR[g] == 0x5C && tmpSTR[g+1] == 0x4E)
								tmpSTR[g] = 0;
						}
						sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
					}
					if(brk2 != 0) {
						sprintf(tmpSTR, "%s", evDialogue[b].lines);
						tmpSTR[lineStart] = 0;
						sprintf(finalAss + strlen(finalAss), "%s", tmpSTR);
						
						// Append italic tag if start tag exists
						if(hasItalic && !hasItalicOFF) {
							printf("Added italic tag. Line: %d\n", b);
							sprintf(finalAss + strlen(finalAss), "%s", (char*)arr_italic);
						}
						
						sprintf(tmpSTR, "%s", &evDialogue[b].lines[brk2+3]);
						int g = 0;
						for(g=0; g<500;++g) {
							if(tmpSTR[g] == 0x5C && tmpSTR[g+1] == 0x4E)
								tmpSTR[g] = 0;
						}
						sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
					}
					
					if(brk3 != 0) {
						sprintf(tmpSTR, "%s", evDialogue[b].lines);
						tmpSTR[lineStart] = 0;
						sprintf(finalAss + strlen(finalAss), "%s", tmpSTR);
						
						// Append italic tag if start tag exists
						if(hasItalic && !hasItalicOFF) {
							printf("Added italic tag. Line: %d\n", b);
							sprintf(finalAss + strlen(finalAss), "%s", (char*)arr_italic);
						}
						
						sprintf(tmpSTR, "%s", &evDialogue[b].lines[brk3+3]);
						int g = 0;
						for(g=0; g<500;++g) {
							if(tmpSTR[g] == 0x5C && tmpSTR[g+1] == 0x4E)
								tmpSTR[g] = 0;
						}
						sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
					}
					
					// Reset this for next processed line
					hasItalic = false;
					hasItalicOFF = false;
					
				#if 0
				// Couldn't get this working perfectly.
					if(brk1 != 0) {
						x_tmp = atoi(&evDialogue[b].lines[brk1+8]);
						if(x == x_tmp) { // match x means let's check y
							if(evDialogue[b].lines[brk1+9] == 0x2C)
								y_tmp = atoi(&evDialogue[b].lines[brk1+10]);
							else if(evDialogue[b].lines[brk1+10] == 0x2C)
								y_tmp = atoi(&evDialogue[b].lines[brk1+11]);
							else if(evDialogue[b].lines[brk1+11] == 0x2C)
								y_tmp = atoi(&evDialogue[b].lines[brk1+12]);
							
							if((y + 15) == y_tmp) //match means no newline, do nothing
								keepLine1 = true;
							else if((y + 16) == y_tmp) // seems to happen sometimes
								keepLine1 = true;
							//printf("Show match: %d\n", keepLine1);
						}
						if(!keepLine1) {
							sprintf(tmpSTR, "%s", evDialogue[b].lines);
							tmpSTR[brk1] = 0;
							sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
							
							sprintf(tmpSTR, "%s", evDialogue[b].lines);
							tmpSTR[lineStart] = 0;
							sprintf(finalAss + strlen(finalAss), "%s", tmpSTR);
							
							sprintf(tmpSTR, "%s", &evDialogue[b].lines[brk1+3]);
							sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
						}
						else {
							sprintf(tmpSTR, "%s", evDialogue[b].lines);
							
							// remove other breaks
							if(brk2 != 0)
								tmpSTR[brk2] = 0;
							
							sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
						}
						//needed?
						keepLine1 = false;
					}
					// rest of breaks
					if(brk2 != 0) {
						//printf("Show x2: %d\n" , x);
						x = x_tmp;
						y = y_tmp;
						
						//printf("Show x2: %d\n\n" , x);
						
						x_tmp = atoi(&evDialogue[b].lines[brk2+8]);
						if(x == x_tmp) { // match x means let's check y
							if(evDialogue[b].lines[brk2+9] == 0x2C)
								y_tmp = atoi(&evDialogue[b].lines[brk2+10]);
							else if(evDialogue[b].lines[brk2+10] == 0x2C)
								y_tmp = atoi(&evDialogue[b].lines[brk2+11]);
							else if(evDialogue[b].lines[brk2+11] == 0x2C)
								y_tmp = atoi(&evDialogue[b].lines[brk2+12]);
							
							if((y + 15) == y_tmp) //match means no newline, do nothing
								keepLine1 = true;
							else if((y + 16) == y_tmp) // seems to happen sometimes
								keepLine1 = true;
							//printf("Show match: %d\n", keepLine1);
						}
						if(!keepLine1) {
							//sprintf(tmpSTR, "%s", evDialogue[b].lines);
							//tmpSTR[brk2] = 0;
							//sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
							
							sprintf(tmpSTR, "%s", evDialogue[b].lines);
							tmpSTR[lineStart] = 0;
							sprintf(finalAss + strlen(finalAss), "%s", tmpSTR);
							
							sprintf(tmpSTR, "%s", &evDialogue[b].lines[brk2+3]);
							sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
						}
						else {
							sprintf(tmpSTR, "%s", evDialogue[b].lines);
						//	if(keepLine1)
							//	tmpSTR[]
							sprintf(finalAss + strlen(finalAss), "%s\n", tmpSTR);
						}
						//needed?
						keepLine1 = false;
					}
					
					if(brk3 != 0) {
						
					}
					
					if(!cntBreaks)
						sprintf(finalAss + strlen(finalAss), "%s\n", evDialogue[b].lines);
				#endif
				}
			}
			// Build the new script
			// do the header stuff
			
			//if(keepLine1) {
				//sprintf(finalAss + strlen(finalAss), "%s\n", evDialogue[b].lines);
			//}
		}
		//printf("THERE ARE %d LINEBREAKS!\n\n", cntBreaks);
	}
	//printf("Total lines: %d\n", lineCNT);
	
	//printf("Show line:\n%s\n\n", evDialogue[1].lines);
	
	//printf("Show size:%d\n\n", strlen(finalAss));
//	printf("Show string:\n%s\n\n", finalAss);
	
	free(subLines);
	
	sprintf(outBuf, "%s", finalAss);
	
	return strlen(finalAss);
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
  printf("~ CC Breakline Tweaker ~  by %s\n\n\n", name);
  
  int d = 0;
  int fileSz = 0;

  int workType = 1;
  FILE *fd = NULL;

  if(argc > 1) {
    for(i = 1; i < (argc); i++) {
            //need to handle special characters or commands
			
			if(strcmp(argv[i], "-i") == 0) {
				fd = fopen(argv[i+1], "rb");
				if(fd == NULL) {
					printf("Failed to open file!\nAre you reading the right spell book?\n\n");
					break;
				} else {
					printf("Opened file for reading: %s\n\n", argv[i+1]);
					workType = 2;
				}
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
                printf("cc2ass.exe -i content.ass\n\n");
                printf("This tool modifies FFmpeg converted CC files\n");
                printf("from EIA-608 format. It fixes multiple \\pos tags\n");
                printf("by placing them in new Dialogue Events.\n\n");
                //printf("\n");
				break;
            }
			
			//work
			if(workType == 2) { //decode
				// get file size
				fseek(fd, 0, SEEK_END);
				fileSz = ftell(fd);
				
				// read the file into mem
				fseek(fd, 0, SEEK_SET);
				uint8_t* datBuf = malloc(fileSz);
				uint8_t* outBuf = malloc(fileSz*4);
				fread(datBuf, 1, fileSz, fd);
				
				//printf("WHAT\n");
				
				int allLines = CountAllLines(datBuf, fileSz);
				int outSize = TweakData(datBuf, 480, fileSz, allLines, outBuf);
				
				// write file
			#if 1
				FILE* fout = fopen("tweaked.ass", "wb");
				fwrite(assHeader, 1, assHeader_size, fout);
				fwrite(outBuf, 1, outSize, fout);
				fclose(fout);
			#endif
				free(datBuf);
				free(outBuf);
				
				printf("\n");
				printf("Done!\n");
				
				break;
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
