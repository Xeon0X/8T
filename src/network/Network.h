#ifndef NETWORK
#define NETWORK

#include <string>
#include "json.hpp"

using json = nlohmann::json;
//  #include <iostream>
//  #include <fstream>
//  #include "json.hpp" // Include the nlohmann/json library
// using json = nlohmann::json;

/**
 * @class network
 * @brief This class is used to create an object that can be sent over lan
 */
class Network
{
private:
    std::string serverIpAddr;   // the ip address of the server
    int PORT;                   // the port of the server
    std::string updateFileName; // the name of the file that will be updated
    std::string saveFileName;   // the name of the file that will be saved
    static bool networkStatus;  // the status of the network

public:
    /**
     * @brief Construct a new Network object
     *
     */
    Network();

    /**
     * @brief Construct a new Network object
     *
     * @param IP
     */
    Network(std::string IP);

    /**
     * @brief Destroy the Network object
     *
     */
    ~Network();

    /**
     * @brief Get the Server IP address
     *
     * @return std::string
     */
    std::string getServerIPaddr(); // get the server ip address

    /**
     * @brief Get the Local IP address
     *
     * @return std::string
     */
    std::string getLocalIpAddr(); // get the local ip address of the computer

    /**
     * @brief Set the Server IP address
     *
     * @param IP
     */
    void setServerIpAddr(std::string IP); // set the server ip address

    /**
     * @brief Get the Port
     *
     * @return int
     */
    void changePort(int port);

    void setupdateFileName(std::string name);
    void setsaveFileName(std::string name);

    int client(std::string mode);

    int server(); // create a server

    int sendFile(); // send a file to the server

    int receiveFile(); // receive the file from the server

    json readJson(); // read the json file and return it

    json readJson(std::string fichier);

    void updateFile(std::string cible, json resultat);

    void updateFile(std::string cible, json resultat, std::string fichier); // this function allows to add elements to a Json file, by specifying a target (it is useful if we want to nest the data)

    void updateFile(json datafile, std::string destinationfile); // this is the same function as just above but without target.

    void deleteFromFile(std::string cible);

    void mergeJson(std::string fromfile, std::string tofile); // this function allows to merge a Json file into another, (so keep the information of the destination file and add others)

    void putbraks(std::string fichier);

    void copyJson(std::string fromfile, std::string tofile); // copy the json and put it in another file (it overwrites the destination file)

    void clearJson();

    void clearJson(std::string fichier);

    void createJson(std::string fichier);

    void afficher(json data);

    void testwrite(std::string fichier);

    void setNetworkStatus(bool status);

    bool getNetworkStatus();
};

#endif // NETWORK