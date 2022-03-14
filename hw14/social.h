class User() {
    private:
        int id;
        string username;
        Community communities[];
        double avgTime;
    public:
        User(string name);
        setUsername();
        getUsername();
        addCommunity();
        deleteCommunity();
        getAvgTimeEngaged();
}

class Community() {
    private:
        int id;
        string name;
        User users[];
        double totalTimeEngaged;
    public:
        Community(string name);
        string getName();
        void setName();
        void addUser(User user);
        void deleteUser(User user);
        double getTotalTimeEngaged();
}