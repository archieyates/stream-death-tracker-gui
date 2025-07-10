#pragma once

class Manager
{
public:
  void init();
  void postInit();
  void shutdown();
  void update();
  void preRender();
  void render();

  bool isInitialised();

protected:
  virtual void onInit() {};
  virtual void onPostInit() {};
  virtual void onShutdown() {};
  virtual void onUpdate();
  virtual void onPreRender();
  virtual void onRender();

private:
  bool m_init{false};
};