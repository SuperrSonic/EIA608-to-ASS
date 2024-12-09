# EIA608-to-ASS
A couple of tools to make using EIA-608 captions actually usable in players that support fancy libass subtitles.

# CC Breakline Tweaker
Run "cc2ass.exe -i film_cc.ass" to output tweaked.ass, it will detect every line (called 'Dialogue Event') for multiple \pos flags and split them into new Dialogue Events. This increases the file size, but allows rendering the EIA-608 positions more accurately.

Normally these multiple \pos flags are ignored, making certain lines awkward when two speakers are going off at the same time.

For example:

![Alt text](https://github.com/user-attachments/assets/1d5219a0-562b-44d1-a6aa-12597c397122 "The Last Dragon - FFmpeg converted")


![Alt text](https://github.com/user-attachments/assets/50584145-9d38-4936-91b3-658fa1265df8 "The Last Dragon - DVD player")


# NF CC 3-Line Tweaker
Netflix is one of the cooler media providers when it comes to supporting stuff. Their main subtitles are a text-based format allowing various things, they can be split into 2 categories: Subtitles and EIA-608.

While subtitles can be converted easily with tools such as SubtitleEdit, their EIA-608 captions are a bit difficult to convert, as they lose a lot of information, mainly the positions, which are pretty important, otherwise the captions can look very messy.

Sometime ago I came across this project: https://github.com/arcusmaximus/YTSubConverter
This tool is able to preserve the positions of Netflix-style closed-captions, the only problem is that multiple lines get a bit misaligned for some reason.
This poor calculation seems to be consistent from my testing, so I wrote a tool that does something similar to my previous effort and goes after every line to find and adjust any multiple linebreaks by checking against a matching timecode.

Run "nf2ass.exe -i episode_01.ass" and it will output tweaked.ass containing the fixed positions.
