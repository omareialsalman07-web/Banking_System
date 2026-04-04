#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

template <class T>
class Repository
{
private:
    std::string _FileName;
public:
    Repository(const std::string& FileName) : _FileName(FileName) {}

    std::vector<T> LoadAll()
    {
        std::vector<T> vList;
        std::fstream file(_FileName, std::ios::in);

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                T obj;
                obj.FromLine(line);
                vList.push_back(obj);
            }
            file.close();
        }
        return vList;
    }
    void SaveAll(const std::vector<T>& list)
    {
        std::fstream file(_FileName, std::ios::out);

        for (const T& obj : list)
        {
            file << obj.ToLine() << std::endl;
        }

        file.close();
    }

    T Find(const std::string& Key)
    {
        std::vector<T> list = LoadAll();

        for (const T& obj : list)
        {
            if (obj.GetKey() == Key)
                return obj;
        }

        return T();
    }
    bool Add(const T& obj)
    {
        if (obj.IsEmpty()) // if the object is empty, Don't add it
            return false;

        if (!Find(obj.GetKey()).IsEmpty()) // if the object already exists, Don't add it again
            return false;

        std::fstream file(_FileName, std::ios::app);
        file << obj.ToLine() << std::endl;
        file.close();

        return true;
    }
    bool Update(T obj)
    {
        bool found = false;

        std::vector<T> vList = LoadAll();

        for (T& item : vList)
        {
            if (item.GetKey() == obj.GetKey())
            {
                item = obj;
                found = true;
                break;
            }
        }
        if (found)
            SaveAll(vList);

        return found;
    }
    void Delete(const std::string& Key)
    {
        std::vector<T> list = LoadAll();

        list.erase(
            std::remove_if(list.begin(), list.end(),
                [&](const T& obj) { return obj.GetKey() == Key; }),
            list.end());

        SaveAll(list);
    }

    inline static std::string GetStandard_ClientsFileName() { return "CLIENTS.txt"; }
    inline static std::string GetStandard_UsersFileName() { return "USERS.txt"; }
};