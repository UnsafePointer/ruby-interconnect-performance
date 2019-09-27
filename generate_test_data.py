#!/usr/bin/env python

import random

with open('input.txt', 'a') as f:
    for x in range(0, 100_000_000):
        f.write("{}\n".format(random.randint(0, 0x1FC00000)))
