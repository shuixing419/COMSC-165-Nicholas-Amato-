#include <iostream>
#include <iomanip>

using namespace std;

// Constants
double Per_Follower = 0.002;
double Engagement_Factor = 0.7;
int main()
{
    double nVideos = 0;
    double nLikes = 0;
    double nFollowers = 0;
    double revenue = 0;
    double engagement_rate = 0;
    //  Get inputs from the user
    cout << "number of the videos? ";
    cin >> nVideos;
    cout << "numer of the likes? ";
    cin >> nLikes;
    cout << "number of the followers? ";
    cin >>nFollowers;
   // The revenue per videos is:

    engagement_rate = nLikes / nVideos / nFollowers * 100;
    revenue = 0.002 * nFollowers + (0.7 * engagement_rate);
    cout << "Revenue per video : $"
         << fixed << setprecision (2) <<revenue
         <<endl;
    //  Successful return
    return 0;
}

