/*
*
*    Copyright (C) Max <max1976@mail.ru>
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#pragma once

#include <Poco/Event.h>
#include <Poco/Task.h>
#include <Poco/Logger.h>
#include <DpdkDevice.h>
#include <DpdkDeviceList.h>
#include <vector>

class extFilter;

class ReloadTask: public Poco::Task
{
public:
	ReloadTask(extFilter *parent, std::vector<pcpp::DpdkWorkerThread*>& workerThreadVector);
	~ReloadTask();
	void runTask();
	static Poco::Event _event;

private:
	extFilter *_parent;
	Poco::Logger& _logger;
	std::vector<pcpp::DpdkWorkerThread*>& workerThreadVec;
};

