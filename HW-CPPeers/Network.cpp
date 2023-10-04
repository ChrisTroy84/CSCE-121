# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include "Network.h"
# include <string>
# include <vector>
# include <cctype>

using std::cout, std::endl;
using std::string, std::vector, std::invalid_argument, std::ifstream, 
std::stringstream, std::runtime_error, std::exception;

Network::Network() : users({vector<User*>()}), posts({vector<Post*>()}), tags({vector<Tag*>()}) {}

void Network::loadFromFile(string fileName) {
    // TODO: load user and post information from file
    ifstream ifs(fileName);

    if (!ifs.is_open()) {
        throw invalid_argument("Error: file could not be opened");
    }
    string input;
    vector<string> half;
    stringstream sstream;
    string word;
    string temp;
    string name;
    string empty;
    size_t tag;
    size_t i;
    unsigned int id_tag = 0;
    
    //inputting for operations
    while (!ifs.eof()) {
        half.clear();
        sstream.clear();

        getline(ifs, input);
        if (input == "") {
            return;
        }

        sstream << input;
        word = "";

        while (!sstream.eof()) {
            sstream >> word;
            half.push_back(word);
        }

        temp = half.at(0);
        //check if user exists
        if (temp == "User") {
            try {
                this->addUser(half.at(1));
            } catch(const exception& err) {
                throw runtime_error(err.what());
            }
        }
        //posting 
        else if (temp == "Post") {
            tag = half.size();
            if (tag < 4) {
                throw runtime_error("Error: invalid format");
            }
            try {
                id_tag = (unsigned int)stoi(half.at(1));
            } catch (const exception& err){
                throw runtime_error(err.what());
            }

            name = half.at(2);
            empty = "";

            for (i = 3; i < tag; i++) {
                empty += half.at(i) + (i != tag - 1 ? " " : " ");
            }

            try {
                this->addPost(id_tag, name, empty);
            }
            catch (const exception& err)   {
                throw runtime_error(err.what());
            }

        }
        else {
            throw runtime_error("Error: Unkown entry" + input);
        }
    }

}

void Network::addUser(string userName) {
    // TODO: create user and add it to network
    size_t i;
    //create a user
    for (i = 0; i < userName.size(); i++) {
        userName.at(i) = tolower(userName.at(i));
    }
    //check to see if user is in network
    for (User* user : users) {
        if (user->getUserName() == userName) {
            throw invalid_argument("Error: " + userName + " is taken");
        }
    }

    users.push_back(new User(userName));
    cout << "Added User " << userName << endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
    // TODO: create post and add it to network
    //post already exists
    for (Post* post : this->posts) {
        if (post->getPostId() == postId) {
            throw invalid_argument("Error: PostID already exists");
        }
    }
    
    Post* post = new Post(postId, userName, postText);

    bool taken = false;

    for (string u_tag : post->findTags()) {
        taken = false;
        for (Tag* tag : this->tags) {
            if (tag->getTagName() == u_tag) {
                tag->addTagPost(post);
                taken = true;
                break;
            }
        }
        //add to network
        if (!taken) {
            try {
                Tag* update_tag = new Tag(u_tag);
                update_tag->addTagPost(post);
                this->tags.push_back(update_tag);
            } catch (const exception& err) {
                continue;
            }
        }
    }

    
    //user->addUserPost(post);
    this->posts.push_back(post);
    cout << "Added Post " << std::to_string(postId) << " by " << userName << endl;
    return;
    
}

vector<Post*> Network::getPostsByUser(string userName) {
    // TODO: return posts created by the given user
    if (userName.empty() || userName == "") {
        throw invalid_argument("Error: User name is empty");
    }
    //I gave up on this lol
    for (User* get_user : this->users) {
        if (get_user->getUserName() == userName) {
            return get_user->getUserPosts();
        }
    }
    throw invalid_argument("Error: User " + userName + " does not exist");
}

vector<Post*> Network::getPostsWithTag(string tagName) {
    // TODO: return posts containing the given tag
    //empty tag throw
    if (tagName.empty() || tagName == "") {
        throw invalid_argument("Error: tag name is empty");
    }
    //returns tagposts
    for (Tag* get_tag : this->tags) {
        if (get_tag->getTagName() == tagName) {
            return get_tag->getTagPosts();
        }
    }
    throw invalid_argument("Tag " + tagName + " does not exists");
}

vector<string> Network::getMostPopularHashtag() {
    // TODO: return the tag occurring in most posts
    vector<string> pop_hashtag;
    int max = 0;
    unsigned int i = 0;
    int count = 0;
    //returns hashtag 
    for (i = 0; i < tags.size(); i++) {
        count = tags[i]->getTagPosts().size();
        if (count > max) {
            max = count;
            pop_hashtag.clear();
            pop_hashtag.push_back(tags[i]->getTagName());
        }
        else if (count == max) {
            pop_hashtag.push_back(tags[i]->getTagName());
        }
    }

    return pop_hashtag;

}

Network::~Network() {
    for (unsigned int i = 0; i < users.size(); ++i) {
        delete users.at(i);
    }

    for (unsigned int i = 0; i < tags.size(); ++i) {
        delete tags.at(i);
    }
    
    for (unsigned int i = 0; i < posts.size(); ++i) {
        delete posts.at(i);
    }
}
