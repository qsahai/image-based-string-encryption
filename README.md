# image-based-string-encryption
This is a c++ program using an encryption algorithm whose complexity lies in the analysis of a chosen image.
The program uses the methods from another project (https://github.com/qsahai/average-color-pixel-finder) to find the average color of a chosen image to locate a "target pixel" to grab a key sequence from its RGB values and, depending on the total pixel count, shifts the individual R, B, and B values around to use as an encryption sequence for the chosen password.


Specifically, if the target image contains an even amount of pixels, the method of traversal to find the target pixel ("Type 1") will involve reading through the image row-by-row to the right and downward. If the total pixel count is odd, the traversal ("Type 2") will read column-to-column downward and to the right.

The key sequence RGB order is as follows:

if total % 3 = 0: RGB
if total % 3 = 1: BRG
if total % 3 = 2: GBR

The sequence will repeat for as many characters in the password (for example, if there are 5 characters with total % 3 = 1, they will be XOR-ed with the sequence in the order BRGBR).


The main file contains a program to ask for a password and an image name, and then encrypts (and decrypts) into the corresponding unsigned integer value.

Requires OpenCV (I used 4.8.0 but most versions should work) and cmake to compile.


To make:

cmake .
make
