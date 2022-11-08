import cs50 as cs


def main():
    cc_num = get_credit_card()
    # print(cc_num[-1])

    is_valid = check_sum(cc_num)

    if is_valid:
        brand = check_brand(cc_num)
        print(brand)
    else:
        print("INVALID")


def get_credit_card():
    while True:
        try:
            number = cs.get_string("Number: ")
            if int(number) > 0:
                return number
        except ValueError:
            continue


def check_sum(cc_num):
    total = 0
    working_cc = int(cc_num)

    while working_cc > 0:
        last_digit = working_cc % 10
        total += last_digit
        working_cc = int(working_cc / 100)

    working_cc = int(int(cc_num) / 10)

    while working_cc > 0:
        last_digit = working_cc % 10
        times = last_digit * 2
        total = total + (times % 10) + int(times / 10)
        working_cc = int(working_cc / 100)

    if total % 10 == 0:
        return True
    else:
        return False


def check_brand(cc_num):
    first_digit = int(cc_num[0])
    first_two_digits = int(cc_num[:2])
    length = len(cc_num)

    if (length == 15) and (first_two_digits == 34 or first_two_digits == 37):
        return "AMEX"

    elif (length == 16) and (51 <= first_two_digits <= 55):
        return "MASTERCARD"

    elif (length == 13 or length == 16) and first_digit == 4:
        return "VISA"

    else:
        return "INVALID"


if __name__ == "__main__":
    main()
