# EIA608-to-ASS
A couple of tools to make using EIA-608 captions actually usable in players that support fancy libass subtitles.

# CC Breakline Tweaker
Run "cc2ass.exe -i film_cc.ass" to output tweaked.ass, it will detect every line (called 'Dialogue Event') for multiple \pos flags and split them into new Dialogue Events. This increases the file size, but allows rendering the EIA-608 positions more accurately.

Normally these multiple \pos flags are ignored, making certain lines awkward when two speakers are going off at the same time.

For example:

![Alt text](https://private-user-images.githubusercontent.com/6880539/394014010-5592a2c2-2d35-4bcd-af21-82a222cdb015.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzM3Nzk1ODYsIm5iZiI6MTczMzc3OTI4NiwicGF0aCI6Ii82ODgwNTM5LzM5NDAxNDAxMC01NTkyYTJjMi0yZDM1LTRiY2QtYWYyMS04MmEyMjJjZGIwMTUuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQVZDT0RZTFNBNTNQUUs0WkElMkYyMDI0MTIwOSUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyNDEyMDlUMjEyMTI2WiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9MTQ4ZjVmYWU1ODMyOTA3NmUxNGFkN2FiYzAwMmMzY2EyMjlkZjk4NzRhYTc1YTgwYjgyZTkwZmY4MDMyNmQ5YyZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.Wh4jmslaqZk-bUG-3s60MfTgWRDsT-VpoZmuudjGtuA "The Last Dragon - FFmpeg converted")

![Alt text](https://private-user-images.githubusercontent.com/6880539/394013988-20766ebd-2000-4f71-b567-52e45f6243fb.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzM3Nzk1ODYsIm5iZiI6MTczMzc3OTI4NiwicGF0aCI6Ii82ODgwNTM5LzM5NDAxMzk4OC0yMDc2NmViZC0yMDAwLTRmNzEtYjU2Ny01MmU0NWY2MjQzZmIuanBnP1gtQW16LUFsZ29yaXRobT1BV1M0LUhNQUMtU0hBMjU2JlgtQW16LUNyZWRlbnRpYWw9QUtJQVZDT0RZTFNBNTNQUUs0WkElMkYyMDI0MTIwOSUyRnVzLWVhc3QtMSUyRnMzJTJGYXdzNF9yZXF1ZXN0JlgtQW16LURhdGU9MjAyNDEyMDlUMjEyMTI2WiZYLUFtei1FeHBpcmVzPTMwMCZYLUFtei1TaWduYXR1cmU9MGRhZTg1M2ExMzJhNTI2MzFkYTljMTI1MTg4NzE4MDI4YjgzMzNiZGRmNGZlZGE5MjY1OThlN2E5ZjkyMzllZCZYLUFtei1TaWduZWRIZWFkZXJzPWhvc3QifQ.lvv0fN416_zFctl_8JA1_sImAOc9hlIwcEyGgUP6hsI "The Last Dragon - DVD player")


# NF CC 3-Line Tweaker
Netflix is one of the cooler media providers when it comes to supporting stuff. Their main subtitles are a text-based format allowing various things, they can be split into 2 categories: Subtitles and EIA-608.

While subtitles can be converted easily with tools such as SubtitleEdit, their EIA-608 captions are a bit difficult to convert, as they lose a lot of information, mainly the positions, which are pretty important, otherwise the captions can look very messy.

Sometime ago I came across this project: https://github.com/arcusmaximus/YTSubConverter
This tool is able to preserve the positions of Netflix-style closed-captions, the only problem is that multiple lines get a bit misaligned for some reason.
This poor calculation seems to be consistent from my testing, so I wrote a tool that does something similar to my previous effort and goes after every line to find and adjust any multiple linebreaks by checking against a matching timecode.

Run "nf2ass.exe -i episode_01.ass" and it will output tweaked.ass containing the fixed positions.
