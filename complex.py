

## This class represents complex numbers.
# It provides methods for addition, subtraction, modulus and a contructor
class Complex:
    ## Creates a complex number.
    # two arguments are used as real and imaginary parts
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    ## Returns the sum of original complex number and argument 
    def add(self, other):
        return Complex(self.real + other.real, self.imag + other.imag)

    ## Returns the diff of original complex number and argument 
    def sub(self, other):
        return Complex(self.real - other.real, self.imag - other.imag)

    ## Returns modulus of complex number
    def abs(self):
        return (self.real ** 2 + self.imag ** 2) ** 0.5
    

x1 = Complex(3.0, -1.0)
x2 = Complex(1.5, 4.0)
x3 = x1.add(x2)