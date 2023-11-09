//A. WAP to display election is contested by five candidates. The candidates are numbered from 1 to 5 and voting is done by accepting the candidate number from voter. Write a program which will accept the votes and count votes for each candidate. If the number typed by voter is outside the range the vote is discarded and the program will keep track of the number of such discarded votes.


#include <stdio.h>

int main() {
    const int numCandidates = 5;
    int candidateVotes[numCandidates] = {0};
    int discardedVotes = 0;
    int voterChoice;

    printf("Election: Contested by Candidates 1 to 5\n");

    while (1) {
        printf("Enter candidate number (1 to 5) or 0 to stop: ");
        scanf("%d", &voterChoice);

        if (voterChoice >= 1 && voterChoice <= numCandidates) {
            // Valid vote
            candidateVotes[voterChoice - 1]++;
        } else if (voterChoice == 0) {
            // Stop accepting votes
            break;
        } else {
            // Discard invalid vote
            discardedVotes++;
            printf("Invalid candidate number. Vote discarded.\n");
        }
    }

    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; ++i) {
        printf("Candidate %d: %d votes\n", i + 1, candidateVotes[i]);
    }

    printf("Discarded Votes: %d\n", discardedVotes);

    return 0;
}
