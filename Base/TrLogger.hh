#include <string>
#include <mysql/mysql.h>

/*! Logging class - singleton */

#ifndef TRLOGGER_HH
#define TRLOGGER_HH

#define SERVER "localhost"
#define USER "cm"
#define PASSWORD "cm"
#define DATABASE "Log"

class TrLogger {
    private:
        // Private Constructor
        TrLogger();
        // Stop the compiler generating methods of copy the object
        TrLogger(TrLogger const& copy);            // Not Implemented
        TrLogger& operator=(TrLogger const& copy); // Not Implemented

	MYSQL *databaseConnection;
	std::string retrieveLevel(int);

    public:
        static TrLogger& getInstance()
        {
            // The only instance
            // Guaranteed to be lazy initialized
            // Guaranteed that it will be destroyed correctly
            static TrLogger instance;
            return instance;
        }
	int openDatabaseConnection();
	int writeLog(std::string, int, std::string, int);
	int closeDatabaseConnection();
};

#endif
