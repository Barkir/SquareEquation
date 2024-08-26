from random import uniform, randint


def square(a, b, c):
    if a != 0:
        d = b * b - 4 * a * c
        if d > 0:
            x1 = (-b - (d ** 0.5)) / (2 * a)
            x2 = (-b + (d ** 0.5)) / (2 * a)
            return sorted([x1, x2]) + [2]
        if d == 0:
            x = -b / (2 * a)
            return [x, 0, 1]
        if d < 0:
            return [0, 0, 0]
    else:
        if b != 0:
            if c != 0:
                return [-c/b, 0, 1]
            else:
                return [0, 0, 1]
        else:
            if c != 0:
                return [0, 0, 0]

            else:
                return [0, 0, -1]


def random_write(file):
    if randint(0, 2):
        a, b, c = round(uniform(-10, 10), 4), round(uniform(-10, 10), 4), round(uniform(-10, 10), 4)
    else:
        a, b, c = round(randint(-10, 10), 3), randint(-10, 10), randint(-10, 10)
    arr = square(a, b, c)
    file.write("\t")
    file.write(str(a))
    file.write("\t")
    file.write(str(b))
    file.write("\t")
    file.write(str(c))
    file.write("\t")
    file.write(str(round(arr[0], 3)))
    file.write("\t")
    file.write(str(round(arr[1], 3)))
    file.write("\t")
    file.write(str(arr[2]))
    file.write("\n")


file = open("rnd_tests.txt", "w+")
file.seek(0)
file.close()
file = open("rnd_tests.txt", "w")

for i in range(100):
    random_write(file)







