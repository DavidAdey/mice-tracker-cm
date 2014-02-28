#include "TrLogger.hh"

/*static TrLogger& TrLogger::getInstance() {
	static TrLogger instance;
	return instance;
}
*/
int TrLogger::openDatabaseConnection() {
	//MYSQL *connect; // Create a pointer to the MySQL instance
	databaseConnection = mysql_init(NULL); // Initialise the instance
    	databaseConnection = mysql_real_connect(databaseConnection,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);
}

int TrLogger::writeLog(std::string message, int severity, std::string file, int line) {
	std::string level = retrieveLevel(severity);
 
	mysql_query(databaseConnection,("INSERT INTO Log (LEVEL, FILE, LINE, MESSAGE) VALUES(%s,%s,%i,%s)",(level, file, line, message)).c_str());
}

std::string TrLogger::retrieveLevel (int severity) {
	std::string level;
	switch(severity) {
		case 0:
			/*! Every function call, value etc. */
			level = "HAPPENINGS";
		case 1:
			/*! Specific values of interest */
			level = "DEBUG";
		case 2:
			/*! What interesting things are happening */
			level = "INFO";
		case 3:
			/*! Something looks awry */
			level = "WARNING";
		case 4:
			/*! Something has gone wrong */
			level = "ERROR";
		case 5:
			/*! The program has crashed, or should crash */
			level = "FATAL";
		case 6:
			/*! It's crashed, and you've probably broken something */
			level = "CATASTROPHIC";
		case 7:
			/*! ... */
			level = "APOCALYPTIC";
		default:
			level = "INFO";
		error:
			level = "ERROR";
	}
	return level;
}
