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

Usage: base_64  --<mode> <data>
|CLI options|:-
        <data> = A data string which will be manipulated.
        <mode>:
                -e, --encode = Encodes the data string
                -d, --decode = Decodes the data string
```
---
## Encoding:
```powershell
base64 --encode "Hack Teh World"
```
Output:
```
SGFjayBUZWggV29ybGQ=
```
---
## Decoding:
```powershell
base64 --encode "SGFjayBUZWggV29ybGQ="
```
Output:
```
Hack Teh World
```
___
<p align=center>&copy; This tool is based on UTF-8 charset.</p>