import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: dna.py database/database_name.csv sequences/sequence_name.txt")

    # Read database file into a variable
    header = []
    str_dict = {}

    with open(sys.argv[1], "r") as f1:

        reader1 = csv.reader(f1)
        for row1 in reader1:
            header.append(row1)

    subsequences = header[0][1:]

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as f2:
        sequence = f2.read()

    # Find longest match of each STR in DNA sequence
    for i in range(len(subsequences)):
        longest_run = longest_match(sequence, subsequences[i])
        str_dict[subsequences[i]] = longest_run

    # print(str_dict)

    # TODO: Check database for matching profiles
    persons = []
    with open(sys.argv[1], "r") as f2:
        reader2 = csv.DictReader(f2)
        for row2 in reader2:
            persons.append(row2)

    for person in persons:
        matched_person = find_matched(str_dict, person)
        if matched_person != 0:
            print(matched_person)
            return 0
        else:
            continue

    print("No match")
    return 1


def find_matched(STR, person):
    man = {
        "name": person["name"],
        "count": 0
    }

    for i in STR:
        if STR.get(i) == int(person.get(i)):
            # print("True")
            man["count"] += 1
        else:
            break
            # print("False")

    if man["count"] == len(STR):
        return man["name"]
    else:
        return 0


def longest_match(sequence, subsequence):
    """Returns length of the longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in the sequence, return longest run found
    return longest_run


main()
