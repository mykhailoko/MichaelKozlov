package main

import (
	"fmt"
)

type Queue struct {
	items []int
}

func NewQueue() *Queue {
	return &Queue{items: make([]int, 0)}
}

func (q *Queue) Push(item int) {
	q.items = append(q.items, item)
}

func (q *Queue) Pop() int {
	if len(q.items) == 0 {
		return 0
	}
	item := q.items[0]
	q.items = q.items[1:]
	return item
}

func (q *Queue) IsEmpty() bool {
	return len(q.items) == 0
}

type Water struct {
	temperature int
}

func NewWater(initialTemperature int) *Water {
	return &Water{temperature: initialTemperature}
}

func (w *Water) GetTemperature() int {
	return w.temperature
}

func (w *Water) HeatUp(degrees int) {
	if w.temperature < 100 {
		w.temperature += degrees
		if w.temperature >= 100 {
			w.temperature = 100
		}
	}
}

type Teapot struct {
	water *Water
}

func NewTeapot(water *Water) *Teapot {
	return &Teapot{water: water}
}

func (t *Teapot) IsBoiling() bool {
	return t.water.GetTemperature() == 100
}

func (t *Teapot) heat_up(degrees int) {
	if !t.IsBoiling() {
		t.water.HeatUp(degrees)
	}
}

func main() {
	var temperature, count int
	fmt.Scan(&temperature, &count)

	heat := NewQueue()
	for i := 0; i < count; i++ {
		var t int
		fmt.Scan(&t)
		heat.Push(t)
	}

	water := NewWater(temperature)
	teapot := NewTeapot(water)

	for !teapot.IsBoiling() {
		teapot.heat_up(heat.Pop())
	}

	for !heat.IsEmpty() {
		fmt.Print(heat.Pop(), " ")
	}
}
