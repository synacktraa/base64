<h1 align="center" style="font-weight: bold">
        Base64 Converter
</h1>       

<p align="center">
	<a href="https://github.com/synacktraa/base64-Converter/blob/master/LICENSE">
        <img src="https://img.shields.io/badge/LICENSE-A31F34?style=flat-square&logoWidth=25&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAANwAAAByCAYAAAA4TL8fAAADvElEQVR4nO3bsYkdVxiG4c2EA6kCY5WgAt2AMuVbgntRC+rgcoeFTRbDcQ3/OxwxjJ8P/vTwBvOE8/J8PteuO47j35cTO47jubNvrfX5RNuvzW1/nWj7ubPt4+PjW21ba33Z2Xb1e9n5OHCn2oC74QHX24ALA27j48CdagPuhgdcbwMuDLiNjwN3qg24Gx5wvQ24MOA2Pg7cqTbgbnjA9TbgwoDb+Dhwp9qAu+EB19uACwNu4+PAnWoD7oYHXG8DLgy4jY8Dd6oNuBsecL0NuDDgNj4O3Kk24G54wPU24MKA2/g4cKfagLvhAdfbgAsDbuPjwJ1qA+6GB1xvAy4MuI2PA3eqDbgbHnC97bLg3t7evr+/v/+z69ZaX2vbWuuPnW1XP+B622XB2YUHXG4DzuYDLrcBZ/MBl9uAs/mAy23A2XzA5TbgbD7gchtwNh9wuQ04mw+43AaczQdcbgPO5gMutwFn8wGX24Cz+YDLbcDZfMDltsuCW2v9vdZ63Xh/nmj7dBzH6657PB4/attvGXC57crgfq69O/M/3OfN39yztv2WAZfbgGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AXRXc4/H4cRzH665ba32qbcDlNuCuCu7KAy63AQfcfMDlNuCAmw+43AYccPMBl9uAA24+4HIbcMDNB1xuAw64+YDLbcABNx9wuQ044OYDLrcBB9x8wOU24ICbD7jcBhxw8wGX24ADbj7gchtwwM0HXG4DDrj5gMttwAE3H3C5DTjg5gMutwEH3HzA5TbggJsPuNwGHHDzAZfbgANuPuByG3DAzQdcbgMOuPmAy23AATcfcLkNOODmAy63AQfcfMDlNuCAmw+43AYccPMBl9uAA24+4HIbcMDNB1xuAw64+YDLbcABNx9wuQ044OYDLrcBB9x8wOU24ICbD7jcBhxw8wGX2/7X4P4DxDPxnlw4RDoAAAAASUVORK5CYII=">
    </a>
    <a href="https://github.com/synacktraa/base64-Converter/network/members">
        <img src="https://img.shields.io/github/stars/synacktraa/base64-Converter.svg?style=flat-square&logo=data:image/png;base64,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">
    </a>
    <a href="https://www.codacy.com/gh/SynAcktraa/base64-Converter/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=SynAcktraa/base64-Converter&amp;utm_campaign=Badge_Grade"><img src="https://app.codacy.com/project/badge/Grade/939d7a865e4743b4acd7c06faef5f12e"/></a>
    
</p>

---
<h4 align="center">
Small and portable Base64 Converter cli tool written in C.
</h4>

---

<h2 align="center">
Usage
</h2>

### Compile
> make
---

### Help

Output:

```terminal
*IMP*: Put space separated data in quotes.
|CLI options|:-
        -e - Encodes the data string
        -d - Decodes the data string
        -i - takes next argument as data string
        -f - takes next argument as filename
        -o - takes next argument as filename and saves the output in file
             (if filename is not given, it defaults to base64Out)
```
---
## Encoding

```bash
./base_64 -e -i "Base64 Converter"
```
Output:

```bash
QmFzZTY0IENvbnZlcnRlcg==
```
---

```bash
./base_64 -e -f infile
```
Output:

```bash
aHR0cHM6Ly9naXRodWIuY29tL1N5bkFja3RyYWE=
```
---
## Decoding
```bash
./base_64 -d -f encoded
```
Output:

```terminal
small portable base64-converter in C.
```
---
```bash
./base_64 -d -i "U3RhciB0aGlzIHByb2plY3QgOiksIGl0IGJvb3N0cyBteSBlZ28u"

```
Output:

```bash
Star this project :), it boosts my ego.
```
---

### **Redirecting output to a file**

<h5> Using the redirection operator↴ </h5>

```bash
./base_64 -d -i "U3RhciB0aGlzIHByb2plY3QgOiksIGl0IGJvb3N0cyBteSBlZ28u" > out.txt
```

<h5> Using the -o argument with a filename↴ </h5>

```bash
./base_64 -d -f encoded -o out
```

<h5> Using the -o argument without a filename↴ </h5>

```bash
./base_64 -e -f infile -o
```
>ps: "-o" without a parameter uses the default filename 'base64Out'

---
<p align=center>&copy; This tool is based on ASCII charset.</p>
