#include "Manager.h"

#include <cassert>
#include <iostream>

void Manager::init()
{
  m_init = true;
  onInit();
}

void Manager::postInit()
{
  if (m_init)
  {
    onPostInit();
  }
}

void Manager::shutdown()
{
  onShutdown();
  m_init = false;
}

void Manager::update()
{
  if (m_init)
  {
    onUpdate();
  }
}

void Manager::preRender()
{
  if (m_init)
  {
    onPreRender();
  }
}

void Manager::render()
{
  if (m_init)
  {
    onRender();
  }
}

bool Manager::isInitialised()
{
  return m_init;
}

void Manager::onUpdate()
{
#ifndef SHIPPING
  std::cerr << "onUpdate called without implementation" << std::endl;
  assert(0);
#endif
}

void Manager::onPreRender()
{
#ifndef SHIPPING
  std::cerr << "onPreRender called without implementation" << std::endl;
  assert(0);
#endif
}

void Manager::onRender()
{
#ifndef SHIPPING
  std::cerr << "onRender called without implementation" << std::endl;
  assert(0);
#endif
}