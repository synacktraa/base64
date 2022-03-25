# Base64 Conversion

>A cli tool based on Base64 algorithm to encode and decode data.

## Help:

>```base_64 -h```

Output:

```

Note: Put space separated data in quotes.
Usage: base_64 <opt> "data"
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
<p align=center>&copy; This tool is based on ASCII charset.</p>
