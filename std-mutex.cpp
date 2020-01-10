#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <map>
#include <string>

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;

void save_page(const std::string& url)
{
	// simulate a long page fetch
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::string result = "fake content";

	g_pages_mutex.lock();
	g_pages[url] = result;
	g_pages_mutex.unlock();
}

int main()
{
	std::thread t1(save_page, "http://www.google.com");
	std::thread t2(save_page, "http://djalmabina.wordpress.com/");
	t1.join();
	t2.join();

	g_pages_mutex.lock();
	for (const auto& pair : g_pages) {
		std::cout << pair.first << " => " << pair.second << '\n';
	}
	g_pages_mutex.unlock();
}
