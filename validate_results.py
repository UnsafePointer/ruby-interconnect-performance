#!/usr/bin/env python

with open('output_before_big2.txt') as f1:
    with open('output_after_big.txt') as f2:
        for cnt, line1 in enumerate(f1):
            line2 = f2.readline()
            if line1 != line2:
                print("Mistatch at line: {}".format(cnt))

