

class FSM;

class scheduler() {
    unordered_map<int, quue<car*>> car;
    unordered_map<int, FSM> mFSM;

}

typedef int eState;
eState NullState = -1;

// 状态的基类
class State
{
public:
    virtual void OnStateEnter() = 0;
    virtual void OnStateTick() = 0;
    virtual void OnStateExit() = 0;

    State(FSM* _fsm)
    {
        fsm = _fsm;
    }
protected:
    FSM* fsm = nullptr;
};

// 状态机，统管所有状态
class FSM
{
private:
    unordered_map<pair<eState,direction>, State*> all_states;
    unordered_map<direction, queue<car*>> car;
    eState curState = -1;
    int curdirection = 0;

public:
	// 注册新的状态
    bool Reigster(eState e, int direction State* pState) {
        all_states[{e,direction}] = pState;
        return true;
    }
	// 需要状态转移则调用此函数
    bool Trans(eState newState)
    {
        all_states[{curState,i}]->OnStateExit();
        all_states[{newState,i}]->OnStateEnter();
        curState = newState;
        direction = direction % 3;
        
    }
	// 设置初始状态
    void SetInitState(eState s)
    {
        curState = s;
    }
	// 每帧调用
    void Tick()
    {
        all_states[{curState,direction}]->OnStateTick(m[driection]);
    }
};

// -----------------实际使用例子开始-----------------
enums status{
    green;
    yellow;
    red;
}

// 实际应用，有三个具体的状态，都从State继承，然后分别实现自己的Enter、Tick、Exit函数

class ongreen : public State
{
public:
    ongreen(FSM *fsm): State(fsm) {}
    queue<car*> curq;
    int test_counter = 0;

    void OnStateEnter(int direction, queue<car*> &q) {
        Turnongreenlight(direction);
        curq = q;
        green_counter = 0;
    }

    void OnStateTick(unordered_map<direction, queue<car*>> &car;) {
        green_counter++;
        movecar(car[i]);
        movecar(car[i + 4 % total]);
        if (test_counter == GREEN_TIMER) {
            fsm->Trans(yellow);
        }
    }

    void OnStateExit(int direction) { 
        turnoffgreenlight(direction);
        green_counter = 0;
     }
};

class onyellow : public State
{
public:
    onyellow(FSM* fsm) : State(fsm) {}

    int yellowc = 0;

    void OnStateEnter() { turnnyellowlight(); yellowc = 0 }

    void OnStateTick() { 
        yellow_counter++;
        slowdown(&car);
        if (test_counter == GREEN_TIMER)
        {
            fsm->Trans(Yellow);
        } 

    void OnStateExit() { 
        turnoffyellowlight();
        green_counter = 0;
    }
};

class onred : public State
{
public:
    onred(FSM* fsm) : State(fsm) {}

    int redc = 0;

    void OnStateEnter() { 
        turnnyellowlight(); 
        redc = 0 }

    void OnStateTick() { 
        red_counter++;
        if (red_counter == GREEN_TIMER) {
            fsm->Trans(red);
        } 

    void OnStateExit() { 
        turnoffredight();
        green_counter = 0;
    }
};

int main()
{
    // 构造状态机
    FSM* fsm = new FSM();
    State* stateIdle = new StateIdle(fsm);
    State* stateAttack = new StateAttack(fsm);
    State* stateGoHome = new StateGoHome(fsm);

    fsm->Register(State_Idle, stateIdle);
    fsm->Register(State_Attack, stateAttack);
    fsm->Register(State_GoHome, stateGoHome);
    fsm->SetInitState(State_Idle);

    // 将状态机Tick放入程序主循环中, 仅示范
    while (TRUE) {
        fsm->Tick();
        sleep(1);
    }

    re
