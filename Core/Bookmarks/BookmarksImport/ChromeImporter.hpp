﻿/***********************************************************************************
** MIT License                                                                    **
**                                                                                **
** Copyright (c) 2018 Victor DENIS (victordenis01@gmail.com)                      **
**                                                                                **
** Permission is hereby granted, free of charge, to any person obtaining a copy   **
** of this software and associated documentation files (the "Software"), to deal  **
** in the Software without restriction, including without limitation the rights   **
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      **
** copies of the Software, and to permit persons to whom the Software is          **
** furnished to do so, subject to the following conditions:                       **
**                                                                                **
** The above copyright notice and this permission notice shall be included in all **
** copies or substantial portions of the Software.                                **
**                                                                                **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    **
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  **
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  **
** SOFTWARE.                                                                      **
***********************************************************************************/

#pragma once
#ifndef SIELOBROWSER_CHROMEIMPORTER_HPP
#define SIELOBROWSER_CHROMEIMPORTER_HPP

#include "BookmarksImporter.hpp"

#include <QFile>

namespace Sn
{
class ChromeImporter: public BookmarksImporter {
Q_OBJECT

public:
	ChromeImporter(QObject* parent = nullptr);
	~ChromeImporter();

	QString description() const;
	QString standardPath() const;

	QString getPath(QWidget* parent);
	bool prepareImport();

	BookmarkItem *importBookmarks();

private:
	void readBookmarks(const QVariantList& list, BookmarkItem* parent);

	QString m_path{};
	QFile m_file{};
};
}

#endif //SIELOBROWSER_CHROMEIMPORTER_HPP