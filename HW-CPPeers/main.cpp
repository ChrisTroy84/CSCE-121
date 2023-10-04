# include <iostream>
# include <string>
# include <stdexcept>
# include "Network.h"

using std::cout, std::cin, std::endl, std::string, std::vector;

void printMenu() {
    cout << "Welcome to CPPeers" << endl;
    cout << "The options are: " << endl;
    cout << "1. load data file and add information" << endl;
    cout << "2. show posts by user" << endl;
    cout << "3. show posts with hashtag" << endl;
    cout << "4. show most popular hashtag" << endl;
    cout << "9. quit" << endl;
    cout << "--------> Enter your option: ";
}

void processLoad(Network& cppeers) {
    string fileName = "";
    cout << "Enter filename: ";
    cin >> fileName;
    cppeers.loadFromFile(fileName);
}

void processPostsByUser(Network& cppeers) {
    // TODO: implement
    string user_name;
    user_name = "";

    cout << "Enter username: ";
    cin >> user_name;

    for (Post* get_post : cppeers.getPostsByUser(user_name)) {
        cout << get_post->getPostText() << endl;
    }
}

void processPostsWithHashtags(Network& cppeers) {
    // TODO: implement
    string tag_name;
    tag_name = "";

    cout << "Enter tagname: ";
    cin >> tag_name;

    for (Post* get_post : cppeers.getPostsWithTag(tag_name)) {
        cout << get_post->getPostText() << endl;
    }
}

void processMostPopularHashtag(Network& cppeers) {
    // TODO: implement

    for (string input : cppeers.getMostPopularHashtag()) {
        cout << input << endl;
    }
    
}

int main() {
    // TODO: uncomment at the end

     try {
         Network cppeers;

         int choice = 0;

         do {
             printMenu();
             cin >> choice;
             switch(choice) {
                 case 1: {
                     processLoad(cppeers);
                     break;
                 }
                 case 2: {
                     processPostsByUser(cppeers);
                     break;
                 }
                 case 3: {
                     processPostsWithHashtags(cppeers);
                     break;
                 }
                 case 4: {
                     processMostPopularHashtag(cppeers);
                     break;
                 }
             }
         } while (choice != 9);
     } catch (std::exception& exc) {
         std::cout << exc.what() << endl;
     }

    return 0;
}
