/*
 * Copyright (C) 2017 Lily Rivers (VioletDarkKitty)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License only.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef ABOUTDIALOGUE_H
#define ABOUTDIALOGUE_H

#include <QDialog>

namespace Ui {
class AboutDialogue;
}

class AboutDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialogue(QWidget *parent = 0);
    ~AboutDialogue();

private:
    Ui::AboutDialogue *ui;
};

#endif // ABOUTDIALOGUE_H
