mystring = "hello"
myfloat = float(10)
myint = 20

if mystring == "hello":
    print("String: %s" % mystring )

if isinstance(myfloat, float) and myfloat == 10.0:
    print("Float: %f" % myfloat)

if isinstance(myint, int) and myint == 20:
    print("Int: %d" % myint)
