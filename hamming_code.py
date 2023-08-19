import numpy as np
from functools import reduce
import operator as op


randBits = np.random.randint(0, 2, 16)
bits = enumerate(randBits)

arrBits = reduce(op.xor, [i for i, bit in enumerate(bits) if bit])

def hammingSyndrome(bits):
    return reduce(
        # Reduce by xor
        lambda x, y: x ^ y,
        # All indices of active bits
        [i for (i, b) in enumerate(bits) if b]
    )

print(hammingSyndrome(randBits))
