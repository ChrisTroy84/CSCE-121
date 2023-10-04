# include <string>
# include <stdexcept>
# include "User.h"

using std::string, std::vector, std::invalid_argument;

User::User(string userName) : userName{userName}, userPosts{vector<Post*>()} {
    // TODO: implement constructor checks
    if (this->userName.empty()) {
        throw invalid_argument("Error: user name cannot be empty");
    }
    
    for (char c : this->userName) {
        if (isupper(c) || (!isalpha(c))) {  
            throw invalid_argument("Error: user name must only contain lowercase letters");
        }
    }
}

string User::getUserName() {
    // TODO: implement getter
    return this->userName;
}

vector<Post*>& User::getUserPosts() {
    // TODO: implement getter
    return this->userPosts;
}

void User::addUserPost(Post* post) {
    // TODO: add post to user posts
    if (post == nullptr) {
        throw std::invalid_argument("Error: post cannot be nullptr");
    }
    this->userPosts.push_back(post);
}
