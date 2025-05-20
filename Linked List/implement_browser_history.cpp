#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-browser-history/

/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:
*/
class PageNode
{
public:
    string m_strURL;
    PageNode *m_ptrNext;
    PageNode *m_ptrPrev;

    PageNode(string url)
    {
        m_strURL = url;
        m_ptrNext = NULL;
        m_ptrPrev = NULL;
    }
};

class BrowserHistory
{
public:
    PageNode *head;
    PageNode *currPage;
    BrowserHistory(string homepage) : head(NULL), currPage(NULL)
    {
        head = new PageNode(homepage);
        currPage = head;
    }

    ~BrowserHistory()
    {
        while (head)
        {
            PageNode *temp = head;
            head = head->m_ptrNext;

            temp->m_ptrPrev = NULL;
            temp->m_ptrNext = NULL;
            delete temp;
        }

        head = NULL;
        currPage = NULL;
    }
    void clearForwardPages(PageNode *currHead)
    {
        while (currHead)
        {
            PageNode *temp = currHead;
            currHead = currHead->m_ptrNext;

            temp->m_ptrPrev = NULL;
            temp->m_ptrNext = NULL;
            delete temp;
        }
    }
    void visit(string url)
    {
        // In real browser if current page URL is same as input URL
        // then forward pages are not cleared
        // if (url == currPage->m_strURL)
        //     return;

        PageNode *newPage = new PageNode(url);
        clearForwardPages(currPage->m_ptrNext);
        currPage->m_ptrNext = newPage;
        newPage->m_ptrPrev = currPage;

        currPage = currPage->m_ptrNext;
    }

    string back(int steps)
    {
        while (currPage->m_ptrPrev && steps)
        {
            currPage = currPage->m_ptrPrev;
            steps--;
        }

        return currPage->m_strURL;
    }

    string forward(int steps)
    {
        while (currPage->m_ptrNext && steps)
        {
            currPage = currPage->m_ptrNext;
            steps--;
        }

        return currPage->m_strURL;
    }
};

int main()
{

    return 0;
}