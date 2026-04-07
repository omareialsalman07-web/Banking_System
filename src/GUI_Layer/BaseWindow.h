#pragma once
#include <iostream>

class BaseWindow
{
private:
    std::string _Title;

protected:
    bool _isOpen = true;

    // -------- Popup State --------
    std::string _ErrorMessage;
    std::string _InfoMessage;

    bool _ShowErrorPopup = false;
    bool _ShowInfoPopup = false;

    bool _CanBeClosed;
	int _ImWindowFlags;

public:
    BaseWindow(const std::string& title, bool canBeClosed = true, int ImWindowFlags = 0);
    virtual ~BaseWindow() = default;

    void Run();

    bool IsOpen() const { return _isOpen; }
    void Close() { _isOpen = false; }

    // -------- Messaging --------
    void ShowError(const std::string& message);
    void ShowMessage(const std::string& message);

protected:
    virtual void Render() = 0; 

    void DrawScreenHeader(const char* text);

private:
    void _RenderPopups();
};