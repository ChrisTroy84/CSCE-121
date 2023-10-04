# include <string>
# include <stdexcept>
# include "Tag.h"

using std::string, std::vector, std::invalid_argument;

Tag::Tag(string tagName) : tagName{tagName}, tagPosts{vector<Post*>()} {
    // TODO: implement constructor checks
    if (this->tagName.length() < 2) {
        throw invalid_argument("Error: Tag name is too short");
    }
    else if (this->tagName.at(0) != '#') {
        throw invalid_argument("Error: Tag name must start with '#'");
    }

    for (char c : this->tagName) {
        if (c == '#') {
            continue;
        }
        if (isupper(c) || (!isalpha(c))) {
            throw invalid_argument("Error: Tag name must only contain lower case letters");
        }
        else if (c == ',' || c == '!' || c == '?' || c == '.') {
            throw invalid_argument("Error: Tag name must only contain lower case letters");
        }
    }

}

string Tag::getTagName() {
    // TODO: implement getter
    return this->tagName;
}

vector<Post*>& Tag::getTagPosts() {
    // TODO: implement getter
    return this->tagPosts;
}

void Tag::addTagPost(Post* post) {
    // TODO: add post to tag posts
    if (post == nullptr) {
        throw std::invalid_argument("Error: post cannot be nullptr");
    }
    this->tagPosts.push_back(post);
}
