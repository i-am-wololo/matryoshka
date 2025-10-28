#!/bin/env python3

import sys

if len(sys.argv) != 3:
    print("wrong arguments")
    print("usage: ./bin2c.py filepath cipherkey")

filename = sys.argv[1]
cipher = sys.argv[2]


def file2bin(file: str):
    result = []
    with open(file, "rb") as file:
        byte = file.read(1)
        while byte != b"":
            result.append("0x"+byte.hex())
            byte = file.read(1)
    return result


def gen_code(binary: list[int], varname: str):
    with open(varname+".h", "w") as file:
        file.write("// generated with bin2c\n\n")
        file.write(f"unsigned char {varname}[] = {{\n")
        for i in range(len(binary)):
            if i%10 == 0:
                file.write("\n")
            file.write(binary[i]+", ")
        file.write("};\n")
        file.write(f"unsigned int {varname}_len = {len(binary)};")

def xor_cipher(binary: list[int], key: int):
    for i in range(len(binary)):
        binary[i] = hex(int(binary[i], base=16) ^ key)
    return binary

if __name__ == "__main__":
    bin = file2bin(filename)
    xor_cipher(bin, int(cipher))
    gen_code(bin, filename)

