#include <iostream>
#include <string>

using namespace std;

class result_set{};


class connection
{
public:
    connection(const string &url) : url{url} {}

    virtual void connect() = 0;
    virtual result_set select(const string &query) = 0;
    virtual void disconnect() const { cout << "Disconnected from " << url << endl; }

protected:
    string url;
};


class mysql_connection : public connection
{
public:
    mysql_connection(const string &url) : connection(url)
    {
        //cout << "Connected to MySQL DB\n";
    }

    void connect() override
    {
        cout << "Connected to MySQL DB\n";
    }

    result_set select(const string &query) override
    {
        return result_set{};
    }

// private:
    // dbc_driver mysql_drv;
};


class oracle_connection : public connection
{
public:
    oracle_connection(const string &url, const string &oracle_specific) : connection(url)
    {
        //cout << "Connected to MySQL DB\n";
    }

    void connect() override
    {
        cout << "Connected to Oracle DB\n";
    }

    result_set select(const string &query) override
    {
        return result_set{};
    }

// private:
    // dbc_driver mysql_drv;
};


class connection_factory
{
public:
    virtual connection *createConnection(const string &url) const = 0;
};


class mysql_connection_factory : public connection_factory
{
public:
    connection *createConnection(const string &url) const override
    {
        return new mysql_connection(url);
    }

    static mysql_connection_factory &instance()
    {
        static mysql_connection_factory single;
        return single;
    }

private:
    mysql_connection_factory() {}

    mysql_connection_factory(const mysql_connection_factory &other) = delete;
};


class oracle_connection_factory : public connection_factory
{
public:
    connection *createConnection(const string &url) const override
    {
        string complicated{"..."};
        return new oracle_connection(url, complicated);
    }

    static oracle_connection_factory &instance()
    {
        static oracle_connection_factory single;
        return single;
    }

private:
    oracle_connection_factory() {}

    oracle_connection_factory(const oracle_connection_factory &other) = delete;
};


connection_factory &getFactory(const string &url)
{
    if (url == "mysql")
        return mysql_connection_factory::instance();
    return oracle_connection_factory::instance();
}


int main()
{
    connection *conn = getFactory("oracle").createConnection("oracle:\/\/localhost/mydb?user=admin&pw=...");
    conn->connect();
    conn->select("SELECT * from user");
    conn->disconnect();

    delete conn;
}