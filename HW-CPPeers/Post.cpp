# include <iostream>
# include <string>
# include <stdexcept>
# include "Post.h"
# include <sstream>

using std::string, std::vector, std::invalid_argument, std::stringstream;

Post::Post(unsigned int postId, string userName, string postText) : postId(postId), userName(userName), postText(postText) {
    if (postId == 0 || userName == "" || postText == "") {
        throw std::invalid_argument("post constructor: invalid parameter values");
    }
}

unsigned int Post::getPostId() {
    return postId;
}

string Post::getPostUser() {
    return userName;
}

string Post::getPostText() {
    return postText;
}

vector<string> Post::findTags() {
    // TODO: extracts candidate tags based on occurrences of # in the post
    vector<string> candidate_tag;
    stringstream sstream(this->postText);
    string tag;
    string u_tag;

    while (!sstream.eof()) {
        sstream >> tag;
        if (tag.at(0) == '#') {
            u_tag = "";
            for (char c : tag) {
                switch(c) {
                case '!':
                    continue;
                case ',':
                    continue;
                case '.':
                    continue;
                case '?':
                    continue;
                default:
                    u_tag += tolower(c);
                }
            }
            candidate_tag.push_back(u_tag);
        }
    }
    return candidate_tag;

}
