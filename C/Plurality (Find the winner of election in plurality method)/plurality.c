#include "../Libraries/cs50.h"
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);  // to check for a valid candidate and update theie vote counts.
void print_winner(void); // to print the name of the winners.

int main(int argc, string argv[]) // taking candidate name from command line arguments.
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) // populating candidate struct with candidates name and votes array.
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: "); // taking the number of voter from user.

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) // iterate through candidates.name to compare each candidates name.
    {
        if (strcmp(name, candidates[i].name) == 0) // check if the candiadates name is valid.
        {
            // printf("same\n");
            candidates[i].votes++; // update the vote count of the candidates by one.
            return true;           // return true because candidate name was valid.
        }
    }
    return false; // return false because candidate name was not valid.
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    string winner[] = {"0", "0", "0", "0", "0", "0", "0", "0", "0"}; // array for all of the name of the winner. Initially length is equal to MAX because highest number of possible winner is 9 & initially it is all string 0.

    int highest_votes = 0; // to determine the number of votes the winner gets.

    for (int i = 0; i < candidate_count; i++) // iterate through all candidates.votes to find the highest number of votes.
    {
        int current_candidate_votes = candidates[i].votes;

        if (current_candidate_votes > highest_votes)
        {
            highest_votes = current_candidate_votes;
        }
    }

    for (int k = 0; k <= candidate_count; k++) // iterate through all candidates.name to find highest number of votes gainer.
    {
        if (candidates[k].votes == highest_votes)
        {
            winner[k] = candidates[k].name; // to assing the name of the candidate in any position of the winner array.
        }
        else
        {
            continue;
        }
    }

    for (int l = 0; l < 9; l++) // iterate through winner array to find the previously winners name.
    {
        if (strcmp(winner[l], "0") == 0) // to avoid string 0 and find winners name.
        {
            continue;
        }
        else
        {
            printf("%s\n", winner[l]); // to print winners name.
        }
    }
}
