#include "btree.hpp"

void InsertInBTree(MyQueue& data, BTree*& root, bool& VR, bool& HR) {
    if (root == nullptr) {
        root = new BTree;
        root->data.push_back(data);
        root->balance = 0;
        root->left = nullptr;
        root->right = nullptr;
        VR = false;
        HR = false;
    }
    else {
        if (data.front()->House_No < root->data.front().head->data->House_No) {
            InsertInBTree(data, root->left, VR, HR);
            if (VR) {
                if (root->balance == 0) {
                    BTree* q = root->left;
                    root->left = q->right;
                    q->right = root;
                    root = q;
                    q->balance = 1;
                    VR = false;
                    HR = true;
                }
                else {
                    root->balance = 0;
                    HR = true;
                }
            }
            else {
                HR = false;
            }
        }
        else if (data.front()->House_No > root->data.front().head->data->House_No) {
            InsertInBTree(data, root->right, VR, HR);
            if (VR) {
                root->balance = 1;
                VR = false;
                HR = true;
            }
            else if (HR) {
                if (root->balance > 0) {
                    BTree* q = root->right;
                    root->right = q->left;
                    q->left = root;
                    root->balance = 0;
                    q->balance = 0;
                    root->left = root;
                    root = q;
                    VR = true;
                    HR = false;
                }
                else {
                    HR = false;
                }
            }
            else {
                HR = false;
            }
        }
        else {
            root->data.push_back(data);
        }
    }
}

void InOrderTraversal(BTree* root, int& counter) {
    if (root == nullptr) {
        return;
    }

    InOrderTraversal(root->left, counter);
    for (size_t i = 0; i < root->data.size(); i++) {
        counter++;
        std::cout << counter << "\t|| " << root->data[i].head->data->FSname << "\t|| "
            << root->data[i].head->data->Street << "\t|| "
            << root->data[i].head->data->House_No << "\t|| "
            << root->data[i].head->data->Flat_No << "\t|| "
            << root->data[i].head->data->Date_of_settlement << "||" << std::endl;
    }
    InOrderTraversal(root->right, counter);
}

void PrintFinderTree(BTree* root, int numhouse, int numflat, int& count) {
    if (root == nullptr) {
        return;
    }

    PrintFinderTree(root->left, numhouse, numflat, count);
    for (size_t i = 0; i < root->data.size(); i++) {
        if (root->data[i].head->data->House_No == numhouse
        && root->data[i].head->data->Flat_No == numflat){
            count++; 
            std::cout << count << "\t|| " << root->data[i].head->data->FSname << "\t|| "
                << root->data[i].head->data->Street << "\t|| "
                << root->data[i].head->data->House_No << "\t|| "
                << root->data[i].head->data->Flat_No << "\t|| "
                << root->data[i].head->data->Date_of_settlement << "||" << std::endl;
        }
    }
    PrintFinderTree(root->right, numhouse, numflat, count);
}

BTree::BTree()
{
    balance = 0;
    left = nullptr;
    right = nullptr;
}