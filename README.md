# The Binary Keyboard

The Binary Keyboard is a 2% keyboard that is able to replace all of the functionality of a fullsize keyboard. This repo contains the custom firmware and some schematics that can be used to construct your own Binary Keyboard.

For a video on this project, click [here](https://www.youtube.com/channel/UC4sLvmZVtLhQag4DVqgPQmw).

## How to Use

The Binary Keyboard works by sending a keypress to correspond with 7 binary digit combination. Printable ASCII characters (alphanumerics and symbols) are outputted by typing their ASCII codes, and other keys are fit around them. See the table below for exact codes.

### Modifier Keys

When the code for a modifier key (<kbd>Shift</kbd>, <kbd>CTRL</kbd>, <kbd>ALT</kbd>, etc.) is typed on the binary keyboard, it is held in a buffer and sent along with the next printable keypress. This means that if you wanted to type <kbd>CTRL</kbd>+<kbd>C</kbd>, you would first type `0000000` for Left <kbd>CTRL</kbd>, then `1100011` for <kbd>C</kbd>. Whenever you are typing keys with modifiers use the lowercase version of the letter, because capital letters send a <kbd>Shift</kbd> along with the letter.

# Key Reference Tables

## Characters

| Key        | Binary Code | Shifted | Shifted Binary Code |
| ---------- | ----------- | ------- | ------------------- |
| `Space`    | `0100000`   |         |                     |
| `Return`   | `0010011`   |         |                     |
| `0`        | `0110000`   | `)`     | `0101001`           |
| `1`        | `0110001`   | `!`     | `0100001`           |
| `2`        | `0110010`   | `@`     | `1000000`           |
| `3`        | `0110011`   | `#`     | `0100011`           |
| `4`        | `0110100`   | `$`     | `0100100`           |
| `5`        | `0110101`   | `%`     | `0100101`           |
| `6`        | `0110110`   | `^`     | `1011110`           |
| `7`        | `0110111`   | `&`     | `0100110`           |
| `8`        | `0111000`   | `*`     | `0101010`           |
| `9`        | `0111001`   | `(`     | `0101000`           |
| `:`        | `0111010`   | `;`     | `0111011`           |
| `=`        | `0111101`   | `+`     | `0101011`           |
| `[`        | `1011011`   | `{`     | `1111011`           |
| `\`        | `1011100`   | `\|`    | `1111100`           |
| `backtick` | `1100000`   | `~`     | `0111110`           |
| `]`        | `1011101`   | `}`     | `1111101`           |
| `'`        | `0100111`   | `"`     | `0100010`           |
| `,`        | `0101100`   | `<`     | `0111100`           |
| `-`        | `0101101`   | `_`     | `1011111`           |
| `.`        | `0101110`   | `>`     | `0111110`           |
| `/`        | `0101111`   | `?`     | `0111111`           |
| `a`        | `1100001`   | `A`     | `1000001`           |
| `b`        | `1100010`   | `B`     | `1000010`           |
| `c`        | `1100011`   | `C`     | `1000011`           |
| `d`        | `1100100`   | `D`     | `1000100`           |
| `e`        | `1100101`   | `E`     | `1000101`           |
| `f`        | `1100110`   | `F`     | `1000110`           |
| `g`        | `1100111`   | `G`     | `1000111`           |
| `h`        | `1101000`   | `H`     | `1001000`           |
| `i`        | `1101001`   | `I`     | `1001001`           |
| `j`        | `1101010`   | `J`     | `1001010`           |
| `k`        | `1101011`   | `K`     | `1001011`           |
| `l`        | `1101100`   | `L`     | `1001100`           |
| `m`        | `1101101`   | `M`     | `1001101`           |
| `n`        | `1101110`   | `N`     | `1001110`           |
| `o`        | `1101111`   | `O`     | `1001111`           |
| `p`        | `1110000`   | `P`     | `1010000`           |
| `q`        | `1110001`   | `Q`     | `1010001`           |
| `r`        | `1110010`   | `R`     | `1010010`           |
| `s`        | `1110011`   | `S`     | `1010011`           |
| `t`        | `1110100`   | `T`     | `1010100`           |
| `u`        | `1110101`   | `U`     | `1010101`           |
| `v`        | `1110110`   | `V`     | `1010110`           |
| `w`        | `1110111`   | `W`     | `1010111`           |
| `x`        | `1111000`   | `X`     | `1011000`           |
| `y`        | `1111001`   | `Y`     | `1011001`           |
| `z`        | `1111010`   | `Z`     | `1011010`           |

## Modifiers

| Key      | Binary Code | Alternate Key | Alternate Key Binary Code |
| -------- | ----------- | ------------- | ------------------------- |
| `LCTRL`  | `0000000`   | `RCTRL`       | `0000101`                 |
| `LSHIFT` | `0000001`   | `RSHIFT`      | `0000110`                 |
| `LALT`   | `0000010`   | `RALT`        | `0000111`                 |
| `LGUI`   | `0000011`   | `RGUI`        | `0001000`                 |

## Other Keys

| Key       | Binary Code |
| --------- | ----------- |
| `UPARROW` | `0001011`   |
| `DNARROW` | `0001100`   |
| `LTARROW` | `0001101`   |
| `RTARROW` | `0001110`   |
| `ESC`     | `0001111`   |
| `INS`     | `0010000`   |
| `DEL`     | `0010001`   |
| `CPSLOCK` | `0010010`   |
| `RETURN`  | `0010011`   |

## Function Keys

| Key   | Binary Code |
| ----- | ----------- |
| `F1`  | `0010100`   |
| `F2`  | `0010101`   |
| `F3`  | `0010110`   |
| `F4`  | `0010111`   |
| `F5`  | `0011000`   |
| `F6`  | `0011001`   |
| `F7`  | `0011010`   |
| `F8`  | `0011011`   |
| `F9`  | `0011100`   |
| `F10` | `001101`    |
| `F11` | `001110`    |
| `F12` | `001111`    |

## Build Instructions

To build this project, you will only need a few parts. The microcontroller I used is an Arduino Pro Micro, which can be found easily and cheaply on eBay or Aliexpress or from any number of keyboard vendors. You will also need 2 switches (I used MX Style keyboard switches but any sort of momentary switch will do), and optionally a 128x32 SSD1306 i2c OLED display.

The schematics included show you the basics of how to prototype a board like this, but if you want to mimic my final design you will need some extra parts. For the final build, I used a [2% Milk PCB from Keyhive](https://keyhive.xyz/shop/milk) as the base of my build. Past that it's up to you whether you want to use an enclosure and how you put the build together in the end.