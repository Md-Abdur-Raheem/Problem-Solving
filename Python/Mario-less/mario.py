def main():
    height = get_height()
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)  # to print blankspace before block

def get_height():
    while True:  # to validate the type & range of input
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                return n
        except:
            continue


if __name__ == "__main__":
    main()
