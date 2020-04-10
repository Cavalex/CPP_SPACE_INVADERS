class Timer
{
	public:
	    Timer() { restart(); }
		void restart() { begin = clock(); }
	    double getTimePassed() { return (clock() - begin) / (double)CLOCKS_PER_SEC; }
	private:
	 	clock_t begin;
};
