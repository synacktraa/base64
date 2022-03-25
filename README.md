# Base64 Conversion

>A cli tool based on Base64 algorithm to encode and decode data.

## Help

>```base_64 -h```

Output:

```bash
Note: Put space separated data in quotes.
Usage: ./base_64 -e/-d <data>
|CLI options|:-
        -e - encodes the data string
        -d - decodes the encoded data
```
---
## Encoding

```bash
./base_64.exe -e "Mom spaghetti"
```
Output:

```bash
TW9tIHNwYWdoZXR0aQ==
```
---
## Decoding

```bash
./base_64 -d "U3RhciB0aGlzIHByb2plY3QgOiksIGl0IGJvb3N0cyBteSBlZ28u"

```

Output:
```bash
Star this project :), it boosts my ego.
```
---
<p align=center>&copy; This tool is based on ASCII charset.</p>
