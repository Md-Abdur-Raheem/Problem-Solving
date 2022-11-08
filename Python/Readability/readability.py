from cs50 import get_string


def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

    # print(l, ",", s, ",", w)


def count_letters(text):
    count = 0

    for i in text:
        if 32 <= ord(i) <= 47 or 58 <= ord(i) <= 64 or 91 <= ord(i) <= 96 or 123 <= ord(i) <= 126:
            continue
        else:
            count += 1

    return count


def count_words(text):
    count = 0

    for i in text:
        if ord(i) == 32:
            count += 1
        else:
            continue

    return count + 1


def count_sentences(text):
    count = 0

    for i in text:
        if ord(i) == 33 or ord(i) == 46 or ord(i) == 63:
            count += 1
        else:
            continue

    return count


if __name__ == "__main__":
    main()
