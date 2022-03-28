# Base64 Converter | <a href="https://www.codacy.com/gh/SynAcktraa/base64-Converter/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=SynAcktraa/base64-Converter&amp;utm_campaign=Badge_Grade"><img src="https://app.codacy.com/project/badge/Grade/939d7a865e4743b4acd7c06faef5f12e"/></a> |

>A cli tool based on base64 algorithm to encode and decode data.

## Help

>`base_64 -h`

Output:

```terminal

*IMP*: Put space separated data in quotes.
Usage: base_64.exe -e/-d -i/-f <data>/<file>
|CLI options|:-
        -e - Encodes the data string
        -d - Decodes the data string
        -i - takes next argument as data string
        -f - takes next argument as filename
```
---
## Encoding

```bash
./base_64.exe -e -i "Base64 Converter"
```
Output:

```bash
QmFzZTY0IENvbnZlcnRlcg==
```
---

```bash
./base_64.exe -e -f infile
```
Output:

```bash
aHR0cHM6Ly9naXRodWIuY29tL1N5bkFja3RyYWE=
```
---
## Decoding
```bash
./base_64.exe -d -f encoded.txt
```
Output:

```terminal
small portable base64-converter in C.
```

```bash
./base_64 -d -i "U3RhciB0aGlzIHByb2plY3QgOiksIGl0IGJvb3N0cyBteSBlZ28u"

```
Output:

```bash
Star this project :), it boosts my ego.
```
---


<p align=center>&copy; This tool is based on ASCII charset.</p>
