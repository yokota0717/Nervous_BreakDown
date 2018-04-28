#include "ClearChecker.h"

ClearChecker::ClearChecker(const std::string& name, Object::Status status):
	Object(name, status),
	check()
{}

bool ClearChecker::checkClear() {
	//if(std::dynamic_pointer_cast<std::weak_ptr<Card>>(check[0])

	//if (front[0].design == 0) {
	//	front[0].design = des;
	//}
	//else if (front[1].design == 0) {
	//	front[1].design= des;
	//}
	//if (check[0] != 0 && check[1] != 0) {
	//	if (check[0] == check[1]) {
	//		return true;
	//	}
	//}
	return false;
}
int ClearChecker::receiveMsg(std::weak_ptr<Object> sender, std::weak_ptr<Object> front) {
	//check.push_back(std::weak_ptr<Card>(front));
	//if (check.size() == 2) {
	//	checkClear();
	//}
	return 0;
}