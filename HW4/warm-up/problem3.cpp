#include <iostream>
#include <string>
using namespace std;

class Movie
{
public:
    Movie(string movieTitle);

    void SetUpVotesAndDownVotes(int numUpVotes, int numDownVotes)
    {
        upVotes = numUpVotes;
        downVotes = numDownVotes;
    }

    string GetTitle() const
    {
        return title;
    }

    int GetUpVotes() const
    {
        return upVotes;
    }

    int GetDownVotes() const
    {
        return downVotes;
    }

private:
    string title;
    int upVotes;
    int downVotes;
};

Movie::Movie(string movieTitle)
{
    title = movieTitle;
    upVotes = 0;
    downVotes = 0;
}

// Two Movie objects are considered equal
// when they have the same number of down votes.
bool operator==(const Movie& movie1, const Movie& movie2)
{
    return movie1.GetDownVotes() == movie2.GetDownVotes();
}

int main()
{
    Movie movie1("It");
    Movie movie2("Taken");

    movie1.SetUpVotesAndDownVotes(8, 2);
    movie2.SetUpVotesAndDownVotes(8, 1);

    if (movie1 == movie2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }

    return 0;
}

/*
Expected output:

Not equal
*/
