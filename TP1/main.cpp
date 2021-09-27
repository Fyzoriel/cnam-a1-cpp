#include <iostream>
#include <vector>
#include <math.h>

int askNumber(int min, int max, std::string message)
{
    int ask;
    bool retry;
    if (min != max)
    {
        message = "Entrez un nombre entier entre " + std::to_string(min) + " et " + std::to_string(max) + ":";
    }
    do
    {
        std::cout << message << std::endl;
        std::cin >> ask;
        if (min == max)
        {
            retry = std::cin.fail();
        }
        else
        {
            retry = std::cin.fail() || ask < min || ask > max;
        }
        std::cin.clear();
        std::cin.ignore();
    } while (retry);
    return ask;
}

int askNumber(int min, int max)
{
    return askNumber(min, max, "Entrez un nombre entier");
}

int askNumber(std::string message)
{
    return askNumber(0, 0, message);

}
int askNumber()
{
    return askNumber("Entrez un nombre entier");
}

bool askSortOrder()
{
    std::string ans;
    do
    {
        std::cout << "Entrez desc pour un tri décroissant, asc pour un tri croissant" << std::endl;
        std::cin >> ans;
        std::cin.clear();
        std::cin.ignore();
    } while (ans != "desc" && ans != "asc");
    return ans == "desc";
}

std::string askFullname()
{
    std::cout << "Entrez votre nom et prénom" << std::endl;
    std::string fullname;
    std::getline(std::cin, fullname);
    return fullname;
}

int somme(int a, int b)
{
    return a+b;
}

void inverse(unsigned int &a, unsigned int &b)
{
    unsigned int t = a;
    a = b;
    b = t;
}

void replace(int a, int b, int *c)
{
    *c = somme(a, b);
}
void replace(int a, int b, int &c)
{
    c = somme(a, b);
}

void generateVector(std::vector<unsigned int> &vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        vector[i] = std::rand() % 20;
    }
}
void displayVector(std::vector<unsigned int> vect)
{
    for (unsigned int i : vect)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

// Bubble sort
void sortVector(std::vector<unsigned int> &vect, bool sortDesc)
{
    bool isFinished = false;
    while (!isFinished)
    {
        isFinished = true;
        for (int i = 0; i < vect.size()-1; i++)
        {
            if ((vect[i] < vect[i+1] && sortDesc)
                || (vect[i] > vect[i+1] && !sortDesc))
            {
                isFinished = false;
                inverse(vect[i], vect[i+1]);
            }
        }
    }
}

void reverseVector(std::vector<unsigned int> &vect)
{
    unsigned int size = vect.size();
    unsigned int middle = floor(size/2);
    for (int i = 0; i < middle; i++)
    {
        inverse(vect[i], vect[size-i-1]);
    }
}

void partI()
{
    // Bonus 1 part 1
    unsigned int size;
    do {
        size = askNumber("Entrez un nombre entier strictement supérieur à 0");
    } while (size < 1);

    std::vector<unsigned int> vect(size);

    generateVector(vect);

    //Bonus 1 part 2
    bool sortDesc = askSortOrder();

    displayVector(vect);
    sortVector(vect, sortDesc);
    displayVector(vect);

    reverseVector(vect);
    displayVector(vect);
}

void incrementScore(unsigned int &score)
{
    if (score < 30)
    {
        score += 15;
    }
    else if (score == 30)
    {
        score = 40;
    }
}

void partII()
{
    std::vector<unsigned int> scoreWin{1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2};
    std::vector<unsigned int> score(2, 0);
    unsigned int advantage = 0;
    unsigned int winner = 404;

    for (unsigned int i : scoreWin)
    {
        unsigned int player = i-1;
        bool isDraw = score[0] == 40 && score[1] == 40;

        // If currently a draw
        if (isDraw)
        {
            // If player have advantage --> win
            if (advantage == player)
            {
                winner = i;
                break;
            }
        }
        else if (score[player] == 40)
        {
            winner = i;
            break;
        }
        else
        {
            incrementScore(score[player]);
        }

        advantage = player;
    }
    if (winner == 404)
    {
        std::cout << "Match en cours" << std::endl;
    }
    else
    {
        std::cout << "Gagnant: joueur " << winner << std::endl;
    }
}

void game(int min, int max)
{
    int secretNumber = std::rand() % max + min;

    int trials = 0;
    int playerNumber;

    do
    {
        trials++;
        playerNumber = askNumber(min, max);
        if (playerNumber < secretNumber)
        {
            std::cout << "Le nombre cherché est plus grand" << std::endl;
        }
        else if (playerNumber > secretNumber)
        {
            std::cout << "Le nombre cherché est plus petit" << std::endl;
        }
    } while(playerNumber != secretNumber);

    std::cout << "Vous avez trouvé le nombre en " << trials << " essaies" << std::endl;
}

void invertedGame(int min, int max)
{
    int secretNumber = askNumber(min, max);
    int trials = 0;
    int choiceNumber;
    bool isLastGreater = true;
    do
    {
        trials++;
        choiceNumber = isLastGreater? ceil((min + max) / 2.0): floor((min + max) / 2.0);
        isLastGreater = choiceNumber < secretNumber;
        if (choiceNumber < secretNumber)
        {
            std::cout << "Le nombre cherché est plus grand que " << choiceNumber << std::endl;
            min = choiceNumber;
        }
        else if (choiceNumber > secretNumber)
        {
            std::cout << "Le nombre cherché est plus petit que " << choiceNumber << std::endl;
            max = choiceNumber;
        }
    } while(choiceNumber != secretNumber);
    std::cout << "Le nombre " << choiceNumber << " a été trouvé en " << trials << " essaies" << std::endl;
}

void trim(std::string &toTrim)
{
    // Rtrim
    toTrim.erase(toTrim.find_last_not_of(' ') + 1);

    //Ltrim
    toTrim.erase(0, toTrim.find_first_not_of(' '));
}

void toUppercase(char &c)
{
    if(c >= 97 && c <= 122)
    {
        c = c-32;
    }
}

void formatNames(std::string &toFormat)
{
    trim(toFormat);
    unsigned int lastpos = toFormat.find_last_of(' ');
    for (int i = 0; i < lastpos+2; i++)
    {
        // Don't handle accented chars
        toUppercase(toFormat[i]);
    }
}

void partIII()
{
    std::string fullname = askFullname();
    // Bonus
    formatNames(fullname);

    std::cout << "Bonjour " << fullname << std::endl;
    // game(0, 1000);
    invertedGame(0, 1000);
}

int main() {
    srand(time(nullptr));
    partI();
    partII();
    partIII();
    return 0;
}
