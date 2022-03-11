class Body {
    private:
        int heads, arms, legs;

    public:
        Body(int numHeads, int numArms, int numLegs);

        void setHeads(int numHeads);
        void setArms(int numArms); 
        void setLegs(int numLegs);

        int getHeads();
        int getArms();
        int getLegs();
};