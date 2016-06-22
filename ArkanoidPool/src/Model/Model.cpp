#include "Model/Model.h"
#include "deserializer/deserializer.h"
#include <iostream>

const unsigned Model::scoreStep = 10;

Model::Model()
: m_briks(0)
, m_scate()
, m_ball(this)
, m_aliveBriks(0)
, m_scores(0)
{
}

Model::~Model()
{
}

void Model::loadLevel(const std::string fileName) {
	deserializer deserializer;
	deserializer.deserialize(fileName, m_briks);
	m_aliveBriks = m_briks.size();
}

void Model::update() {
	m_scate.update();
	m_ball.update();
	checkCollision();
}

void Model::checkCollision() {
	// TODO what am i going to do with fps?
	if (m_ball.isLaunched()) {
		for (std::size_t i = 0; i < m_briks.size(); ++i) {
			if (m_briks[i].isAlive() && m_ball.isCollision(m_briks[i].getCoord())) {
				m_briks[i].boom();
				m_scores += scoreStep;
				if (!m_briks[i].isAlive()) {
					m_aliveBriks--;
				}
				break;
			}
		}
	}
}

unsigned Model::getLives() const {
	return m_ball.getLives();
}

void Model::reset() {
	m_briks.clear();
	m_ball.reset();
	m_scate.reset();
}