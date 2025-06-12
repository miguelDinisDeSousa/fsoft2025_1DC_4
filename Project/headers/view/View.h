//
// Created by carlo on 12/06/2025.
//

#ifndef FSOFT2025_1DC_4_VIEW_H
#define FSOFT2025_1DC_4_VIEW_H

class View {
public:
    int AppMenu(bool = false, bool = true);
    int AdminMenu(bool admin, bool = true);
    int ContactMenu(bool = true);
    int MessageMenu(bool = true);
    int GroupChatMenu(bool = true);
    int NotificationMenu(bool = true);
};

#endif //FSOFT2025_1DC_4_VIEW_H
