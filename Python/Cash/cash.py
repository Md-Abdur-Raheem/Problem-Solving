from cs50 import get_float
from math import floor


def main():
    cents = get_cents()

    quarters = calculate_change(cents, 25)
    cents = cents - quarters * 25

    dimes = calculate_change(cents, 10)
    cents = cents - dimes * 10

    nickels = calculate_change(cents, 5)
    cents = cents - nickels * 5

    pennies = calculate_change(cents, 1)
    cents = cents - pennies * 1

    coins = quarters + dimes + nickels + pennies

    print(coins)


def get_cents():
    while True:
        try:
            cents = get_float("Change owed: ")
            if cents > 0:
                return cents * 100
        except:
            continue


def calculate_change(cents, value):
    if cents % value == 0:
        return cents / value

    elif (cents > value and cents % value != 0):
        return floor(cents / value)

    elif cents < value:
        return 0


if __name__ == "__main__":
    main()