def main():
    h = get_height()
    for i in range(1, h + 1):
        print(" " * (h - i) + "#" * i + "  " + "#" * i)


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                return n
        except:
            continue


if __name__ == "__main__":
    main()