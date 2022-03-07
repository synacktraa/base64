# Base64 Conversion

>Base64 encoding and decoding algorithm implemented in C.

Compile:

```powershell
gcc base64.c utils.c -o base64
```
---
Ask For Help:

>```base_64 -h```

Output:

```

Note: Put space separated data in quotes.
Usage: E:\GIT\Clang_Projects\Base64\base_64.exe <opt> "data"
|CLI options|:-
        -e - Encodes the data string
        -d - Decodes the data string
```
---
## Encoding:
```powershell
base_64 -e "Hack Teh World"
```
Output:
```
SGFjayBUZWggV29ybGQ=
```
---
## Decoding:
```powershell
base_64 -d "SGFjayBUZWggV29ybGQ="
```
Output:
```
Hack Teh World
```
___
<p align=center>&copy; This tool is based on UTF-8 charset.</p>