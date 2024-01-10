s = """0 28 0 0 0 10 0 
28 0 16 0 0 0 14 
0 16 0 12 0 0 0 
0 0 12 0 22 0 18 
0 0 0 22 0 25 24 
10 0 0 0 25 0 0 
0 14 0 18 24 0 0"""

mat = [[int(i) for i in k.split()] for k in s.split("\n")]
for i in range(len(mat)):
    for j in range(len(mat)):
        if(i!=j and mat[i][j] == 0):
            print(999,end = " ")
        else:
            print(mat[i][j],end = " ")
    print()

s = "{\n"
for i in range(len(mat)):
    s += "{"
    for j in range(len(mat)):
        if(i!=j and mat[i][j] == 0):
            s += "999,"
        else:
            s += str(mat[i][j])+","
    s = s[:len(s)-1]+"},\n"
s+="}"
print(s)


